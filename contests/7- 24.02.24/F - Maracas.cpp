#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> odd;

    int k;

    for (int i = 0; i < n; i++) {
        cin >> k;

        if (k%2 == 1) odd.push_back(i);
    }

    int l, r; cin >> l >> r;

    int cost = min(l,r);

    int dir;

    if (cost == r) dir = -1;

    int sz = odd.size();

    if (sz%2 == 1) {cout << -1; return 0;}

    int final_cost = 0, cost2 = 0;

    for (int i = 0; i < sz; i+=2) {
        int k = (i+dir)%sz; if (k < 0) k += sz;

        int dist = (odd[i]-odd[k]*dir)%n; if (dist < 0) dist += n;

        final_cost += dist * cost;
    }

    cout << min(final_cost, final_cost);
    

    
    

    return 0;
}