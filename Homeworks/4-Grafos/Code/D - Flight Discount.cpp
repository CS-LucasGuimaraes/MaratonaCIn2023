#include <bits/stdc++.h>

#define ll long long
#define int long long
#define float long double

using namespace std;

int32_t main(){
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

    int father = parent[cities];
    vector<int> path;

    path.push_back(father);

    while (father != 1) {
        father = parent[father];
        path.push_back(father);
    }

    float max = 0;

    for (auto e:path) {
        if (dist[e]-dist[parent[e]] > max) max = dist[e]-dist[parent[e]];
    }

    int ceil_max = ceil(max/2);

    cout << dist[cities]-ceil_max;

    return 0;
}


/*
Test case broking:
5 5
1 2 2
2 3 2
3 4 2
4 5 2
1 4 7

expected: 5 | 1->4 (7/2 cost == 3) + 4->5(cost 2)
myoutput: 7 | 1->2 (cost 2) + 2->3 (cost 2) + 3->4 (cost 2) + 4->5(2/2 cost == 1)

Explanation: When we have a normal route that costs more than other route but, aplying the discount in the lower route we get an higher value than aplying the discount to the higher route. The discount in a higher value is higher than in an lower value. Sometimes it's better to pickup the higher path.
*/