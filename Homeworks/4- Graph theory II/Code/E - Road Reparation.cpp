#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cities, roads;

    cin >> cities >> roads;

    vector<vector<pair<int,int>>> adj(cities+1);

    int x, y, cost;

    for (int i = 0; i < roads; i++) {
        cin >> x >> y >> cost;

        adj[x].push_back({cost, y});
        adj[y].push_back({cost, x});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> operation_order;
    vector<bool> visited(cities+1, false);
    int mst_totalWeight = 0;

    operation_order.push({0, 1});
    while(!operation_order.empty()) {
        int out = operation_order.top().second;
        int cost = operation_order.top().first;
        operation_order.pop();

        if (visited[out]) continue;
        visited[out] = true;
        
        mst_totalWeight += cost;

        for(auto e: adj[out]) {
            if (!visited[e.second]) {
                operation_order.push({e.first, e.second});
            }   
        }
    }

    for (int i = 1; i < cities+1; i++) {
        if (!visited[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    cout << mst_totalWeight;

    return 0;
}