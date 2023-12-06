#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int boxes, queries;

    cin >> boxes >> queries;

    vector<map<int,int>> adj(boxes+1);

    int x, y;

    int n = boxes+1;

    for (int i = 1; i < n; i++) {
        cin >> x;
        adj[i][x] = 1;
    }

    for (int i = 0; i < queries; i++) {
        cin >> x >> y;
        if (adj[x].size() <= adj[y].size()){
            for (auto e:adj[x]) {
                adj[y][e.first] += e.second;
            }
            adj[x].clear();
        }
        else {
            for (auto e:adj[y]) {
                adj[x][e.first] += e.second;
            }

            swap(adj[y], adj[x]);
            adj[x].clear();
        }

        cout << adj[y].size() << '\n';
    }

    return 0;
}