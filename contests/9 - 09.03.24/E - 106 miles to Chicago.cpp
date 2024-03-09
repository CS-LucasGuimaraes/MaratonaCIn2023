#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve(int tc) {

    int places = tc, roads; cin >> roads;
    vector<vector<pair<int,int>>> adj(places+1);

    int x, y, prob;

    for (int i = 0; i < roads; i++) {
        cin >> x; cin >> y; cin >> prob;

        adj[x].push_back({prob, y});
        adj[y].push_back({prob, x});
    }

    priority_queue<pair<double,int>> operation_order;      // Max heap
    vector<bool> visited(places+1, false);
    vector<double> safeness(places+1, 0);

    safeness[1] = 1;                                    // Elemento neutro
    
    operation_order.push({1,1});
    while (!operation_order.empty()) {
        int a = operation_order.top().second;           
        operation_order.pop();

        if (visited[a]) continue;
        visited[a] = true;

        for (auto e: adj[a]) {
            double s = e.first; int b = e.second;
            if (safeness[a]*(s/100) > safeness[b]) {
                safeness[b] = safeness[a]*(s/100);
                operation_order.push({safeness[b], b});
            }
        }
    }   

    cout << safeness[places] * 100 << " percent";

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(6) << fixed;

    int tc; cin >> tc;
    while(tc) {
        solve(tc);
        cin >> tc;
        if (tc) cout << endl;
    }

    return 0;   
}