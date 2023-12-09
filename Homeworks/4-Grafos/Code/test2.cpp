#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int vertex, edges;

    cin >> vertex; cin >> edges;

    vector<vector<pair<int,int>>> adj(vertex+1);

    int x, y, cost;

    for (int i = 0; i < edges; i++) {
        cin >> x; cin >> y; cin >> cost;

        adj[x].push_back({cost, y});
    }

    for (auto e:adj) {
        sort(e.begin(), e.end());
    }

    for (auto e:adj) {
        e[0]
    }
    

    return 0;
}