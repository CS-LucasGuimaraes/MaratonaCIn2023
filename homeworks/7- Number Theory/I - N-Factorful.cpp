#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int LIM = 1e6+5;

vector<ll> divisors(LIM, 0);

void Sieve()
{
    // vector<int> prime(n + 1, 1);
 
    for (ll i = 2; i < LIM; i++) {
        if (divisors[i] == 0) {
            for (ll j = i; j < LIM; j += i) {
                divisors[j]++;
            }
        }
    }
}

vector<vector<int>> dp(1e6 + 1, vector <int> (10 + 1, 0));

void precompute() {

    for(int i = 1; i <= 1e6; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            dp[i][j] = dp[i - 1][j];
        }
        dp[i][divisors[i]]++;
    }

}

int solve() {

    int a, b, n; 
    
    cin >> a; cin >> b; cin >> n;

    int l, r, answ;

    l = min(a,b); r = max(a,b);

    answ = dp[r][n] - dp[l-1][n];

    if (l == 1 and n == 0) answ = 1;

    cout << answ << endl;
    
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Sieve();
    precompute();

    int tc; cin >> tc; while (tc--) {
        solve();
    }
    
    return 0;
}

