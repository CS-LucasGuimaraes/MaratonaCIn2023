#include <bits/stdc++.h>

#define endl '\n'

using ll = long long;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        ll n, k;

        cin >> n >> k;

        if (n % 2 == 0 ) {
            cout << "Yes" << endl;
            continue;
        }
        if (k % 2 == 0 ) {
            cout << "No" << endl;
            continue;
        }

        if (n >= k) {
            cout << "Yes" << endl;
            continue;
        }
        
        cout << "No" << endl;
    }

    return 0;
}