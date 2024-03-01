#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;
using ll = long long;

const int max_size = 2e5+5;
vector<ll> bit(max_size+1, 0);
int n, q;

void add(int idx, int val) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val) {
    add(l, val);
    if (r < n)
    add(r + 1, -val);
}

int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

ll qry(int i){ // [1,i] 1 indexado
	ll ret = 0;
	for(; i > 0; i -= i & -i){
		ret += bit[i];
	}
	return ret;
}

ll qryRange(int l, int r){ // 1 indexado inclusivo
	ll qr = qry(r);
	ll ql = qry(l-1);
	return qr-ql;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    ll x;

    for (int i = 1; i <= n; i++) {
        cin >> x;

        range_add(i, i, x);
        cout << i << " - " << qryRange(i,i) << endl;

    }

    int id;
    int a, b, u;
    int k;

    for (int i = 1; i <= q; i++) {
        cin >> id;

        if (id == 1) {
            cin >> a >> b >> u;
            range_add(a, b, u);
            
        } 

        else if (id == 2) {
            cin >> k;
            cout << point_query(k) << endl;
        }

    }

    return 0;
}