#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve() {

    int price; cin >> price;
    int buildings; cin >> buildings;
    int streets; cin >> streets;

    vector<vector<pair<int,int>>> adj(buildings+1);

    int x, y, lenght;
    for (int i = 0; i < streets; i++) {
        cin >> x >> y >> lenght;

        adj[x].push_back({lenght, y});
        adj[y].push_back({lenght, x});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> operation_order; //min heap
    vector<bool> visited(buildings+1, false);

    int mst_weight = 0;

    operation_order.push({0, 1});

    while (!operation_order.empty()) {
        pair<int,int> pair = operation_order.top();
        operation_order.pop();
        
        int len = pair.first;
        int out = pair.second;

        if (visited[out]) continue;
        visited[out] = true;
        mst_weight += len;

        for(auto e: adj[out]) {
            if (!visited[e.second]) {
                operation_order.push(e);
            }
        }
    }

    cout << mst_weight * price << endl;

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}