#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll nodes, conections;
    ll x, y;

    cin >> nodes; cin >> conections;

    vector<ll> adj[nodes+1];

    for (ll i = 0; i < conections; i++) {
        cin >> x; cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    priority_queue<ll, vector<ll>, greater<ll>> operation_order;
    vector<bool> visited;

    visited.assign(nodes+1, false);

    operation_order.push(1);
    visited[1] = true;
    while (!operation_order.empty()) {
        ll i = operation_order.top();
        operation_order.pop();
        cout << i << " ";
    
        for (auto e:adj[i]) {
            if (!visited[e]) {
                operation_order.push(e);
                visited[e] = true;
            }
        }
    }

    return 0;
}