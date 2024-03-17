#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int INF = INT_MAX;
const int max_size = 1e6+1e3+10;
vector<ll> seg(4*max_size);
vector<int> arr(max_size, 0);
const int n = max_size - 1;

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
	seg[index] = max(seg[left], seg[right]);
}

ll query(int L, int R, int l = 0, int r = n-1, int index = 0){
	if(R < l || L > r) return -INF; // elemento neutro
	if(L <= l && r <= R) return seg[index];

	int mid = l + (r-l)/2;
	int left = 2*index + 1;
	int right = 2*index + 2;
	ll ql = query(L,R,l,mid,left);
	ll qr = query(L,R,mid+1,r,right);
	return max(ql,qr); 
}

void update(int pos, int num, int l = 0, int r = n-1, int index = 0){
	if(l == r){
		seg[index] += num;
		return;
	}
	int mid = l + (r-l)/2;
	int left = 2*index + 1;
	int right = 2*index + 2;
	if(pos <= mid){
		update(pos,num,l,mid,left);
	}
	else update(pos,num,mid+1,r,right);
	seg[index] = max(seg[left],seg[right]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int servers, queries; cin >> servers >> queries;

    build();

    int initial, needed, duration; 

    for (int i = 0; i < queries; i++) {
        cin >> initial >> needed >> duration;
        if (needed + query(initial, initial+duration) <= servers) {
            for (int j = initial; j <= initial+duration; j++) {
                update(j, needed);
            }
        }
        else {
            cout << -1;
        }
    }
    



    return 0;
}