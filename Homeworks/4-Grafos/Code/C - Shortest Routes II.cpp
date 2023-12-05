    #include <bits/stdc++.h>

    #define int long long
    #define INF 5e13

    using namespace std;

    int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(0);

        int cities, roads, queries;

        cin >> cities; cin >> roads; cin >> queries;

        int n = cities+1;

        vector<vector<int>> adj(cities+1, vector<int>(cities+1, INF));

        int x, y, len;

        for (int i = 0; i < roads; i++) { //lê os valores e guarda na lista de adjacência
            cin >> x; cin >> y; cin >> len;

            adj[x][y] = min(len, adj[x][y]); //evitar erro com 2 arestas entre os mesmos nodos com pesos diferentes
            adj[y][x] = min(len, adj[y][x]); //~ 
        }

        vector<vector<int>> distance(cities+1, vector<int>(cities+1, 0));

        for (int i = 1; i < n; i++) { //matriz com as distâncias iniciais de vertice a vertice
            for (int j = 0; j < n; j++) {
                if (i == j) distance[i][j] = 0;
                else if (adj[i][j]) distance[i][j] = adj[i][j];
                else distance[i][j] = INF;
            }   
        }
    // cout << "AQUI!" << endl;

        for (int k = 0; k < n; k++) { //algoritimo de Floyd-Warshall
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
                }   
            }
        }

        for (int i = 0; i < queries; i++) { //print das distâncias
            cin >> x; cin >> y;
            
            if (distance[x][y] == INF) cout << -1 << '\n'; 
            else cout << distance[x][y] << '\n';
        }

        return 0;
    }