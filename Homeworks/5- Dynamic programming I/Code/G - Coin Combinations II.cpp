#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int coins, sum;
    cin >> coins >> sum;

    int coin;

    vector<int> values;

    for (int i = 0; i < coins; i++) {
        cin >> coin;

        values.push_back(coin);
    }

    vector<vector<ll>> dp(coins+1,vector<ll>(sum+1,0));
    dp[0][0] = 1;

    for (int i = 1; i < coins+1; i++) {
        for (int j = 0; j < sum+1; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-values[i-1] >= 0) {
                dp[i][j] += dp[i][j-values[i-1]] % MOD;
                dp[i][j] %= MOD;
            } 
        }
    }
    
    cout << dp[coins][sum] ;

    return 0;
}