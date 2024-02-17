#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int a;

    int odd = 0;
    int even = 0;

    for (int i = 0; i < n; i++) {
        cin >> a;

        if (a%2 == 0) even++; else odd++;
    }

    if (odd %2 == 0 and odd >= 2) cout << "First" << endl;
    else if (odd %2 == 1) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}