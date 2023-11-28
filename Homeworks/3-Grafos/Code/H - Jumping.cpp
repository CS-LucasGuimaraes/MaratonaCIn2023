#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("jumping.in", "r", stdin);
   //freopen("*.out", "w", stdout);

    int test_cases;

    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        int shoppings, x;
        cin >> shoppings;
        vector<vector<int>> adj(shoppings+1);

        for (int i = 1; i < shoppings+1; i++) {
            cin >> x;
            if (i-x > 0) adj[i].push_back(i-x);
            if (i+x <= shoppings) adj[i].push_back(i+x);
        }

        for (int i = 1; i < shoppings+1; i++) {
            queue<int> operation_order;
            vector<bool> visited(shoppings+1, false);
            vector<int> dist(shoppings+1, 10e5+2);

            operation_order.push(i);
            visited[i] = true;
            dist[i] = 0;
            while (!operation_order.empty()) {
                int j = operation_order.front();
                operation_order.pop();
                vector<int> k = adj[j];
                for (auto e:k) {
                    if (!visited[e]) {
                        operation_order.push(e);
                        if (dist[e] > dist[j] + 1) dist[e] = dist[j] + 1;
                        visited[e] = true;
                    }
                }
            }
            if (dist[shoppings] != 10e5+2) cout << dist[shoppings] << '\n';
            else cout << -1 << '\n';
        }
        
    }
    

    return 0;
}