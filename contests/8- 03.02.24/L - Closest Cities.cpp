#include <bits/stdc++.h>

#define endl '\n'
#define int long long //change main to int32_t

using namespace std;
using pii = pair<int,int>;

const int INF = 1e9+10;

int solve() {

    int cities, queries;

    cin >> cities;

    vector<int> dist(cities+1);
    vector<int> pos(cities+1);
    vector<pii> adj(cities+1);

    dist[0] = 0;
    pos[0] = 0;

    for (int i = 1; i <= cities; i++) {
        cin >> pos[i];

        dist[i] = pos[i] - pos[i-1];
    }

    adj[1] = {INF, 1};
    adj[cities] = {1, INF};

    for (int i = 2; i <= cities-1; i++) {
        if (dist[i] > dist[i+1]) {
            adj[i] = {dist[i], 1};
        }
        else { //if (dist[i] < dist[i+1]) 
            adj[i] = {1, dist[i+1]};
        }
    }

    cin >> queries;

    vector<int> prefix0(cities+2), prefix1(cities+1);
    prefix0[cities+1]=0; prefix1[0]=0;

    for (int i = 1; i <= cities; i++) {
        prefix1[i] = prefix1[i-1] + adj[i].second;
        prefix0[cities+1-i] += prefix0[cities+2-i] + adj[cities+1-i].first;
    }
    

    int x, y;

    for (int i = 0; i < queries; i++) {
        cin >> x >> y;

        int sum = 0;

        if (y > x) {
            sum = prefix1[y-1] - prefix1[x-1];
        }

        else {
            sum = prefix0[y+1] - prefix0[x+1];
        }

        cout << sum << endl;

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