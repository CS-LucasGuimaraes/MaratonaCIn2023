#include <bits/stdc++.h>

#define endl '\n'
#define int long long //change main to int32_t

using namespace std;


const int INF = 1e9+10;



int solve() {

    int cities, queries;

    cin >> cities;

    vector<vector<int>> mat(cities+1, vector<int>(cities+1, INF));
    vector<int> dist(cities+1);
    vector<int> pos(cities+1);

    dist[0] = 0;
    pos[0] = 0;

    for (int i = 1; i <= cities; i++) {
        cin >> pos[i];

        dist[i] = pos[i] - pos[i-1];
    }

    mat[1][2] = 1;
    mat[cities][cities-1] = 1;

    for (int i = 2; i <= cities-1; i++) {
        if (dist[i] > dist[i+1]) {
            mat[i][i+1] = 1;
            mat[i][i-1] = dist[i];
        }
        else { //if (dist[i] < dist[i+1]) 
            mat[i][i-1] = 1;
            mat[i][i+1] = dist[i+1];
        }
    }

    for (int i = 0; i <= cities; i++) {
        mat[i][i] = 0;
    }
    

// -------------------------------------------------------------------------- //

    for (int k = 1; k <= cities; k++) {
        for (int i = 1; i <= cities; i++) {
            for (int j = 1; j <= cities; j++) {
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }

// -------------------------------------------------------------------------- //

    cin >> queries;

    int x, y;

    for (int i = 0; i < queries; i++) {
        cin >> x >> y;

        cout << mat[x][y] << endl;

    }

    return 0;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}