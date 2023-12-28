#include <bits/stdc++.h>

#define endl '\n'
#define INF INT_MAX

using namespace std;
using iii = tuple<int,int,int>;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        int cities, roads;
        cin >> cities >> roads;

        vector<vector<pii>> adj(cities+1);

        int a, b, d;

        for (int i = 0; i < roads; i++) {
            cin >> a >> b >> d;

            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
        }

        vector<int> bikes;

        bikes.push_back(0);

        for (int i = 0; i < cities; i++) {
            cin >> a;

            bikes.push_back(a);
        }

        priority_queue<iii, vector<iii>, greater<iii>> operation_order;
        vector<int> dist(cities+1, INF);

        dist[1] = 0;
        operation_order.push({0,1,bikes[1]});

        while(!operation_order.empty()) {
            iii op = operation_order.top();
            operation_order.pop();

            int len = get<0>(op);
            int out = get<1>(op);

            if (len > dist[out]) continue;

            for(auto e: adj[out]) {
                int bik = get<2>(op);
                int next = e.second;
                int cost = e.first * bik;
                int current_distance = dist[out] + cost;
                if (current_distance < dist[next]) {
                    if (bikes[next] < bik) bik = bikes[next];
                    dist[next] = current_distance;
                    operation_order.push({current_distance, next, bik});
                }
            }
        }

        cout << dist[cities] << endl;


    }

    return 0;
}

// corner case: vale a pena ir, pegar a bike, voltar e continuar o caminho.
// 5 5
// 1 2 2
// 3 2 1
// 2 4 5
// 2 5 7
// 4 5 1
// 5 2 1 3 3