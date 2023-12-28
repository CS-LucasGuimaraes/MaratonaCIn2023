#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        int a, b, c;

        cin >> a >> b >> c;

        if (a == b) cout << c << endl;
        else if (a == c) cout << b << endl;
        else if (b == c) cout << a << endl;
    }

    return 0;
}