#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tc; cin >> tc;

    while(tc--) {
        ll x; cin >> x;

        while(x % 2 == 0){
            x  /= 2;
        }

        if (x != 1) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}