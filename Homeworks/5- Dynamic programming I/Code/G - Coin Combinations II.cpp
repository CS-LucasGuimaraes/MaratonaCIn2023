#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MOD = 1e9+7; // Por que eu tomo TLE se eu não usar const?

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

    vector<ll> dp(1e6+1);
    dp[0] = 1;

    for (int i = 1; i < coins+1; i++) {
        for (int j = 0; j < sum+1; j++) {
            if (j-values[i-1] >= 0) {
                dp[j] += dp[j-values[i-1]];
                dp[j] %= MOD;
            }
        }
    }
    
    // for (int i = 0; i < sum; i++) { // printing for debug
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    
    cout << dp[sum] ;

    return 0;
}