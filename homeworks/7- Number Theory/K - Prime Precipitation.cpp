    #include <bits/stdc++.h>

    #define endl '\n'

    using namespace std;
    using ll = long long;

    vector<ll> prime_list;
    vector<ll> memoprime(5e6, -1);

    void SieveOfEratosthenes(ll n) {
        vector<bool> prime(n + 1, true);
    
        for (ll p = 2; p <= n; p++) {
            if (prime[p] == true) {
                memoprime[p] = 1;
                prime_list.push_back(p);

                for (ll i = p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
    }


    ll prime_factors(int k, int i = 0) {
        if (memoprime[k] != -1) return memoprime[k];
        
        if (k % prime_list[i] == 0) {
            return memoprime[k] = (1 + prime_factors(k / prime_list[i], 0));
        }
        
        else {
            return memoprime[k] = (prime_factors(k, i+1));
        }

    }

    vector<ll> memo(5e6, -1);

    ll seconds(int k) {
        if (memo[k] != -1) return memo[k];

        return memo[k] = (1 + seconds(k-prime_factors(k)));
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);

        SieveOfEratosthenes(5e6);
        memo[1] = 0;


        int k; cin >> k;
        // int k = 6;

        ll sec = 0;

        for (int i = k; i > 1; i--) {
            sec += seconds(i);
        }
        
        cout << sec << endl;
        
        return 0;
    }

