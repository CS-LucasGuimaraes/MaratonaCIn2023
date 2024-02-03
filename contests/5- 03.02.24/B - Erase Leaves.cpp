#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int INF = INT_MAX;

vector<vector<int>> adj(3e5+2);
vector<int> weight(3e5+2, -1);
vector<bool> visited(3e5+2, false);

int def_weight(int n) {
    visited[n] = true;

    if (weight[n] != -1) {
        return weight[n];
    }

    vector<int> weight_list;

    if (adj[n].size() == 1) return 1;

    for (auto e: adj[n]) {
        if (!visited[e]) weight_list.push_back(def_weight(e));
        else weight_list.push_back(INF);
    }

    sort(weight_list.begin(), weight_list.end());

    int sum = 0;

    for (int i = 0; i < weight_list.size()-1; i++) {
        sum += weight_list[i];  
    }

    return weight[n] = sum + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << def_weight(1);
    
    return 0;
}