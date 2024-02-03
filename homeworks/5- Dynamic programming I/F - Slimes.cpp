#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;

    vector<int> slimes(n);
    vector<int> bestsum(n);


    cin >> slimes[0]; bestsum[0] = 0;

    for (int i = 1; i < n; i++) {
        cin >> slimes[i];

        bestsum[i] = slimes[i] + slimes[i-1];
    }

    for (auto e:slimes) cout << e << ' ';
    cout << '\n';
    for (auto e:bestsum) cout << e << ' ';

    return 0;
}