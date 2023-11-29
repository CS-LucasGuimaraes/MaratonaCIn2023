#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int people, laces;
    int x,y;

    cin >> people; cin >> laces;

    vector<vector<int>> adj(people+1);

    for (int i = 0; i < laces; i++) {
        cin >> x; cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i < people+1; i++) {
        if (adj[i].size() == 0) {
            cout << "=[";
            return 0;
        }
    }

    queue<int> operation_order;
    vector<int> dist(people+1, 2e3+2);
    int maxdist = 0;

    for (int i = 1; i < people+1; i++){
        vector<bool> visited(people+1, false);
        operation_order.push(i);
        visited[i] = true;
        dist[i] = 0;
        
        while (!operation_order.empty()) {
            int j = operation_order.front();
            operation_order.pop();

            for (auto e:adj[j]) {
                if (!visited[e]) {
                    operation_order.push(e);
                    if (dist[e] > dist[j] + 1) dist[e] = dist[j] + 1;
                    if (dist[e] > maxdist) maxdist = dist[e];
                    visited[e] = true;
                }
            }
        }

    }
    
    cout << "=] " << maxdist;

    return 0;
}