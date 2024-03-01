#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int max_size = 2e5+5;
vector<ll> arr(max_size+1,0);
vector<ll> bit(max_size+1,0);
int n, q;

ll query(int i){ // [1,i]
	ll ret = 0;
	for(; i > 0; i -= i & -i){
		ret += bit[i];
	}
	return ret;
}

ll queryRange(int l, int r){
	ll qr = query(r);
	ll ql = query(l-1);
	return qr-ql;
}
void increment(ll i, ll v){
	for(; i <= n; i += i & -i){
		bit[i] += v;
	}
}
void build(const vector<ll>& nums){
	for(int i = 0; i < nums.size(); i++){
		increment(i+1,nums[i]);
	}
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

        increment(i, arr[i]-arr[i-1]);
    }

    int id;
    int a, b, u;
    int k;

    for (int i = 1; i <= q; i++) {
        cin >> id;

        if (id == 1) {
            cin >> a >> b >> u;
            increment(a, u);
            increment(b+1, (-u));
            
        } 

        else if (id == 2) {
            cin >> k;
            cout << query(k) << endl;
        }

    }

    return 0;
}