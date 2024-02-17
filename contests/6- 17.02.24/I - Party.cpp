#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int friends; cin >> friends;

    vector<vector<int>> friendships(n+1);    

    int a, b;

    for (int i = 0; i < friends; i++) {
        cin >> a >> b;

        friendships[a].push_back(b);
        friendships[b].push_back(a);
    }

    int haters; cin >> haters;

    vector<vector<int>> unfriendships(n+1);

    for (int i = 0; i < haters; i++) {
        cin >> a >> b;

        unfriendships[a].push_back(b);
    }
    
    vector<bool> visited(n+1, false);
    queue<int> operation_order;

    int maxgroup = 0;

    for (int i = 1; i < n+1; i++) {
        if (visited[i]) continue;
        visited[i] = true;

        vector<int> group;

        operation_order.push(i);
        group.push_back(i);

        while(!operation_order.empty()) {
            int front = operation_order.front();
            operation_order.pop();

            for (auto e: friendships[front]) {
                if (visited[e]) continue;
                
                visited[e] = true;
                operation_order.push(e);

                group.push_back(e);
            }
        }

        bool impossible = false;

        for (auto e: group) {
            for (auto k: unfriendships[e]) {
                
                if (find(group.begin(), group.end(), k) != group.end()) {
                    impossible = true;
                }
                if (impossible) break;

            }
            if (impossible) break;
        }

        if (impossible) continue;

        int sz = group.size();
        maxgroup = max(maxgroup, sz);
    }

    cout << maxgroup << endl;
    

    return 0;
}