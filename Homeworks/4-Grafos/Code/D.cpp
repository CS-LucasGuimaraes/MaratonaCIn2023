#include <bits/stdc++.h>

#define INF 10e6

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int cities, connections;

    cin >> cities >> connections;

    vector<vector<vector<pair<int,int>>>> adj(cities);
    // vector<vector<int>> adj(cities, vector<int>(cities, INF));

    int a, b, price; 

    for (int i = 0; i < connections; i++) {
        cin >> a >> b >> price;

        adj[0][a].push_back({price, b});
        adj[1][a].push_back({floor(price/2), b});
    }


    // From start to n; from n to z w/ discount; from z to final;
    // who's n and z?

    return 0;
}