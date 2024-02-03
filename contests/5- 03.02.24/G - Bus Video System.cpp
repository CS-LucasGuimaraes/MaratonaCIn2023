#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int bus_stops; cin >> bus_stops;
    ll capacity; cin >> capacity;

    vector<int> screen;

    int a;
    for (int i = 0; i < bus_stops; i++) {
        cin >> a;

        screen.push_back(a);
    }

    vector<int> prefix_sum(bus_stops);

    prefix_sum[0] = screen[0];
    for (int i = 1; i < bus_stops; i++) {
        prefix_sum[i] = screen[i] + prefix_sum[i-1];
    }

    sort(prefix_sum.begin(), prefix_sum.end());
    
    ll max, min;

    if (prefix_sum[0] < 0) min = -prefix_sum[0];
    else min = 0;

    if (prefix_sum[bus_stops-1] >= 0) max = capacity - prefix_sum[bus_stops-1];
    else max = capacity;


    // cout << "MAX: " << max << ' ' << "MIN: " << min << endl;
    // for (auto e:prefix_sum) cout << e << ' ';
    // cout << endl;

    if (min > max ) cout << 0;
    else cout << max-min+1;

    return 0;
}