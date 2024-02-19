#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    string s; cin >> s;

    int i = 0;

    for (char c: s) {
        if (c == 'A') i++;
    }

    char x = i >= 3 ?  'A' : 'B'; 

    cout << x << endl;

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