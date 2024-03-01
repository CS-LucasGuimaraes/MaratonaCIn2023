#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int INF = INT_MAX;
const int max_size = 2e5 + 5;
vector<ll> seg(4*max_size);
vector<ll> arr(max_size);
int n,q;

void build(int l = 0, int r = n-1, int index = 0){
	if(l == r){
		seg[index] = arr[l];
		return;
	}
	int mid = l + (r-l)/2;
	int left = 2*index + 1;
	int right = 2*index + 2;
	build(l,mid,left);
	build(mid+1,r,right);
	seg[index] = min(seg[left], seg[right]);
}

ll query(int L, int R, int l = 0, int r = n-1, int index = 0){
	if(R < l || L > r) return INF; // elemento neutro
	if(L <= l && r <= R) return seg[index];

	int mid = l + (r-l)/2;
	int left = 2*index + 1;
	int right = 2*index + 2;
	ll ql = query(L,R,l,mid,left);
	ll qr = query(L,R,mid+1,r,right);
	return min(ql,qr); 
}

void update(int pos, int num, int l = 0, int r = n-1, int index = 0){
	if(l == r){
		seg[index] = num;
		return;
	}
	int mid = l + (r-l)/2;
	int left = 2*index + 1;
	int right = 2*index + 2;
	if(pos <= mid){
		update(pos,num,l,mid,left);
	}
	else update(pos,num,mid+1,r,right);
	seg[index] = min(seg[left],seg[right]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int queries; cin >> n >> queries;

    // arr[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build();

    int id, a, b;

    for (int i = 0; i < queries; i++) {
        cin >> id >> a >> b;

        if (id == 1) {
            update(a-1, b);
        }

        else if (id == 2) {
            cout << query(a-1, b-1) << endl;
        }
    }

    return 0;
}