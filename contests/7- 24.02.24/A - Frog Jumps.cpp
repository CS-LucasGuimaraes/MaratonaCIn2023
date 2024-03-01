#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    string s; cin >> s;

    int answ = 1;
    int k = 1;

    for (auto c: s) {
        if (c == 'L') {
            k++;
            answ = max(answ, k);
        }
        else k = 1;
    }

    cout << answ << endl;

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    // duplicated bug

    return 0;
}