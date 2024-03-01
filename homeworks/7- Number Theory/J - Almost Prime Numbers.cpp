#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

vector<ll> prime_list;

void SieveOfEratosthenes(ll n)
{
    vector<bool> prime(n + 1, true);
 
    for (ll p = 2; p <= n; p++) {
        if (prime[p] == true) {
            prime_list.push_back(p);

            for (ll i = p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

vector<vector<int>> almost_prime();

int solve() {

    ll lower, upper;
    cin >> lower >> upper;

    int c = 0;
    for (int i = 0; prime_list[i]*prime_list[i] <= upper; i++) {
        ll product = prime_list[i]*prime_list[i];
        while (product <= upper) {
            if (product >= lower) {
                c++;
            }
            product *= prime_list[i];
        }
    }
    
    cout << c << endl;
    

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    SieveOfEratosthenes(1e6);

    int tc; cin >> tc; while (tc--) {
        solve();
    }
    
    return 0;
}