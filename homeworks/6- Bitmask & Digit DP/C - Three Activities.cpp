#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int solve() {
    int winter_duration; cin >> winter_duration;

    vector<pair<int,int>> skiing;
    vector<pair<int,int>> movies;
    vector<pair<int,int>> bGames;

    int a, b, c;

    for (int i = 0; i < winter_duration; i++) {
        cin >> a;

        skiing.push_back({a, i});
    }

    for (int i = 0; i < winter_duration; i++) {
        cin >> b;

        movies.push_back({b, i});
    }

    for (int i = 0; i < winter_duration; i++) {
        cin >> c;

        bGames.push_back({c, i});
    }

    sort(skiing.begin(), skiing.end(), greater<pair<int,int>>());
    sort(movies.begin(), movies.end(), greater<pair<int,int>>());
    sort(bGames.begin(), bGames.end(), greater<pair<int,int>>());

    int sum;
    int bestsum = 0;

    for (int i = 0; i < 3; i++) {   //O(3^3)
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                sum = skiing[i].first + movies[j].first + bGames[k].first;
                if (skiing[i].second != movies[j].second &&
                    skiing[i].second != bGames[k].second &&
                    movies[j].second != bGames[k].second ) {
                    
                    if (sum > bestsum) bestsum = sum;
                }
            }
        }
    }

    return bestsum;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int answ;

    int tc; cin >> tc; while (tc--) {
        answ = solve();

        cout << answ << endl;
    }

    return 0;
}