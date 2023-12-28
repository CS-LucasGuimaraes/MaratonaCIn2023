#include <bits/stdc++.h>

#define endl '\n'
#define int long long

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int tc; cin >> tc; while (tc--) {
        int buckets; cin >> buckets;
        int sum = 0; int a;

        for (int i = 0; i < buckets; i++) {
            cin >> a;
            sum += a;
        }

        int rad;

        rad = sqrt(sum);

        if (rad*rad == sum) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }

    return 0;
}