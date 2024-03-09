#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int n, has_to, cant; cin >> n >> has_to >> cant;
    int k = 1;

    for (int i = has_to; i <= n; i+=k) {
        if (i % has_to == 0) {
            if (i % cant != 0) {
                k = has_to;
                cout << i << ' ';
            }
        }
    }
    cout << endl;
    

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}