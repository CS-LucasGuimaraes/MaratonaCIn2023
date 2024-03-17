#include <bits/stdc++.h>

#define endl '\n'
#define int long long

using namespace std;
using ll = long long;

const int INF = INT_MAX;
const int max_size = 1e6 + 5;
vector<ll> seg(4*max_size);
vector<ll> arr(max_size);
ll n,q, n2;

vector<ll> prime_list;

void SieveOfEratosthenes(ll n3)
{
    vector<bool> prime(n3 + 1, true);
 
    for (ll p = 2; p <= n3; p++) {
        if (prime[p] == true) {
            prime_list.push_back(p);

            for (ll i = p; i <= n3; i += p)
                prime[i] = false;
        }
    }
}

ll max_prime(ll n4) {
	ll i =0;
	ll answ = 1;
	while (n4 >= prime_list[i]) {
		if (n4%prime_list[i]==0) answ = prime_list[i];
		
		i++;
	}
	return answ;
}

void build(int l = 0, int r = n-1, int index = 0){
	if(l == r){
		seg[index] = max_prime(arr[l]);
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
	seg[index] = max(seg[left],seg[right]);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

	SieveOfEratosthenes(1e6);

    int queries; cin >> n >> queries;
	n2 = n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build();

    int id, a, b;

    for (int i = 0; i < queries; i++) {
        cin >> id;

        if (id == 1) {
            for (int k = 1; k <= n2; k++) {
                if (n2+1-k <= k) {break;}

				arr[k-1] += arr[n2-k];
                arr[n2-k] = 0;

                update(k-1, max_prime(arr[k-1]));
                update(n2-k, 0);
            }
				// CEIL DE n2/2
			if (n2%2==0) n2 = n2/2;
			else n2 = (n2+1)/2;
        }

        else if (id == 2) {
            cin >> a >> b;
            cout << query(a-1, b-1) << endl;
        }
    }

    return 0;
}