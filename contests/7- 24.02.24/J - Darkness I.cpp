#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    int a, b; a = max(n,m); b = min(n,m);

    cout << b + int(ceil(float(a-b)/2));
    return 0;
}