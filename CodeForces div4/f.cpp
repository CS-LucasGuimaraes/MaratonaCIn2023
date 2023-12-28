#include <bits/stdc++.h>

#define endl '\n'
#define int long long 

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        int people; cin >> people;
        int a, b;

        vector<pair<int,int>> pos;

        for (int i = 0; i < people; i++) {
            cin >> a >> b;

            pos.push_back({b, a});
        }

        sort(pos.rbegin(), pos.rend());
        
        int sum = 0;

        for (int i = 0; i < people; i++) {
            for (int j = i; j < people; j++) {
                if (i == j) continue;

                if ((pos[i].second < pos[j].first) && (abs(pos[j].second-pos[j].first) < abs(pos[i].second-pos[j].first)))
                    sum++; 
            }
            
        }
        
        cout << sum << endl;
    }

    return 0;
}