#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int max_size = 1e5 + 5;
vector<double> seg(4*max_size);
vector<double> arr(max_size);
int n,q;

double sum(double a, double b){
	return a+b;
}

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
	seg[index] = sum(seg[left], seg[right]);
}

double query(int L, int R, int l = 0, int r = n-1, int index = 0){
	if(R < l || L > r) return 0; // elemento neutro
	if(L <= l && r <= R) return seg[index];

	int mid = l + (r-l)/2;
	int left = 2*index + 1;
	int right = 2*index + 2;
	double ql = query(L,R,l,mid,left);
	double qr = query(L,R,mid+1,r,right);
	return sum(ql,qr); 
}

void update(int pos, double num, int l = 0, int r = n-1, int index = 0){
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
	seg[index] = sum(seg[left],seg[right]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(15) << fixed;

    cin >> n;

    // arr[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build();	

    int queries; cin >> queries;

    int id;

    int i, j; 
    double f;

    for (int k = 0; k < queries; k++) {
        cin >> id;

        if (id == 1) {
            cin >> i; cin >> f;

            update(i-1, f);
        }

        else if (id == 2) {
            cin >> i >> j;
            cout << (query(i-1, j-1)) / (j-i+1)<< endl;
        }
    }

    return 0;
}