#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int squares, streets; cin >> squares >> streets;

    vector<vector<int>> adj(squares+1);
    vector<int> degree(squares+1,0);

    int x, y;
    for (int i = 0; i < streets; i++) {
        cin >> x >> y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);

        degree[x]++; degree[y]++;
    }
    
    degree[0] = squares;
    pair<int, int> min_degree = {squares, 0};

    int c = -1;
    for (auto e: degree) {
        c++;
        if (e < min_degree.first) min_degree = {e, c};
    }

    degree[min_degree.second] = -1;
    for (auto e: adj[min_degree.second]) {
        degree[e] = -1;
    }

    for (int i = 1; i <= squares; i++) {
        if (degree[i]!=-1) cout << 1 << ' ';
        else cout << 0 << ' '; 
    }

    return 0;
}