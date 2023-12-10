#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases; cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        int x;
        char c;

        cin >> c; cin >> x;

        for (int i = 1; i < 9; i++) {
            if (i == x) continue;
            cout << c << i << '\n';
        }

        for (int i = 1; i < 9; i++) {
            if (int(c) - 96 == i) continue;
            cout << char(96+i) << x << '\n';
        }

    }
    

    return 0;
}