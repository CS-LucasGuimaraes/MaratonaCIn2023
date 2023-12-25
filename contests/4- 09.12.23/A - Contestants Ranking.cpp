#include <bits/stdc++.h>

#define INF 10e5

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases; cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        int team_number; cin >> team_number;

        map<string, int> rank;
        vector<tuple<string, string, string>> teams;

        string a, b, c;
        for (int i = 0; i < team_number; i++) {
            cin >> a >> b >> c;

            if (b == "Ahmad") swap(b, a);
            if (c == "Ahmad") swap(c, a);

            teams.push_back({a, b, c});

            rank[a] = INF;
            rank[b] = INF;
            rank[c] = INF;
        }

        for (auto e: teams) {
            if (get<0>(e) == "Ahmad") {
                rank[get<0>(e)] = 0;
                rank[get<1>(e)] = 1;
                rank[get<2>(e)] = 1;
            }
        }

        for (auto e: teams) {
            if (get<0>(e) == "Ahmad") continue;

            int a = rank[get<0>(e)];
            int b = rank[get<1>(e)];
            int c = rank[get<2>(e)];

            rank[get<0>(e)] = min(min(a, b+1), c+1);
            rank[get<1>(e)] = min(min(a+1, b), c+1);
            rank[get<2>(e)] = min(min(a+1, b+1), c);
        }

        for (auto e: teams) {
            if (get<0>(e) == "Ahmad") continue;

            int a = rank[get<0>(e)];
            int b = rank[get<1>(e)];
            int c = rank[get<2>(e)];

            rank[get<0>(e)] = min(min(a, b+1), c+1);
            rank[get<1>(e)] = min(min(a+1, b), c+1);
            rank[get<2>(e)] = min(min(a+1, b+1), c);
        }

        cout << rank.size() << '\n';

        vector<vector<pair<string, int>>> order(rank.size()+1);

        for (auto e: rank) {
            if (e.second == INF) order[rank.size()].push_back({e.first, e.second});
            else order[e.second].push_back({e.first, e.second});
        }

        for (auto k: order) {
            for (auto e: k) {
                cout << e.first << " "; 
                if (e.second == INF) cout << "undefined" << '\n'; 
                else cout << e.second << '\n';
            }
        }
        
    }
    

    return 0;
}