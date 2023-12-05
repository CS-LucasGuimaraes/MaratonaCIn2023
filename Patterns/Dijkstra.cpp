#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cities, flights;

    cin >> cities; cin >> flights;

    vector<vector<pair<int,int>>> adj(cities+1);

    int x, y, lenght;

    for (int i = 0; i < flights; i++) {
        cin >> x; cin >> y; cin >> lenght;

        adj[x].push_back({lenght, y});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> operation_order; //min heap
    vector<ll> parent(cities+1, 0);
    vector<ll> dist(cities+1, 1e14);

    dist[1] = 0;
    operation_order.push({0,1});
    while (!operation_order.empty()) {
        pair<int,int> pair = operation_order.top();
        operation_order.pop();
        
        int len = pair.first;
        int out = pair.second;

        if (len > dist[out]) continue; // se o peso do nodo atual for maior que a dist() da saida, continue;

        for(auto e: adj[out]) {
            ll cost = e.first;
            ll next = e.second;
            ll current_distance = dist[out] + cost;
            if (current_distance < dist[next]) {
                dist[next] = current_distance;
                parent[next] = out;
                operation_order.push({current_distance, next});
            } 
        }
    }

    return 0;
}

