#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    if (n%2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll answ = pow(2, n/2);

    cout << answ << endl;

    return 0;
}