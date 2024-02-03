#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
const int MOD = 1e9+7; 

vector<int> calculed_fact(1e6, -1);


int fact(int n){
    if (calculed_fact[n] != -1) {
        return calculed_fact[n];
    }

    if (n == 1 || n == 0) return 1;

    return calculed_fact[n] = n * fact(n-1) % MOD;    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int teams; cin >> teams;
    int chairs; cin >> chairs;

    int empty_chairs; empty_chairs = chairs - (teams*3);

    int empty_multiplier;
    
    empty_multiplier = fact(teams+empty_chairs) / ((fact(empty_chairs) * fact(teams)) % MOD) ;
    
    
    cout << (
        ((( (int(pow(6, teams)) % MOD) * fact(teams)) % MOD) * empty_multiplier) % MOD);
    
    return 0;
}