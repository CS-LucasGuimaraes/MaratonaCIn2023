#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int INF = INT_MAX;

int n; 
vector<vector<int>> dp(12, vector<int>(4096,-1));
int matrix[12][12];

int solveDp(int node, int mask) {
    if (mask == (1 << n) - 1) return dp[node][mask] = matrix[node][0];
    if (dp[node][mask] != -1) return dp[node][mask];

    int answ = INF;

    for (int i = 0; i < n; i++) {
        if ((mask & (1<<i)) == 0) {   // if the bit i is unpowered    // if i didn't visited it yet
            answ = min(answ, matrix[node][i] + solveDp(i, mask | (1<<i)));
        }
    }
    return dp[node][mask] = answ;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    if (n == 1) cout << 0 << endl;
    else cout << solveDp(0,1) << endl;
}


void reset() {

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 4096; j++) {
            dp[i][j] = -1;
        }
        
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        reset();

        solve();
    }

    return 0;
}