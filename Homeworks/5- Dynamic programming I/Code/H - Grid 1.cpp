#include <bits/stdc++.h>

#define int long long
#define MOD 1000000007

using namespace std;

int dx[] = {0,1};
int dy[] = {1,0};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col;
    char b;

    cin >> row; cin >> col;

    char board[row][col];

    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(b);
            board[i][j] = b;
        }
    }
    
    vector<vector<int>> dp(row, vector<int>(col, 0));
    queue<pair<int,int>> operation_order;
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int x, y, i, j;

    operation_order.push({0,0});
    dp[0][0] = 1;
    while(!operation_order.empty()) {
        x = operation_order.front().first;
        y = operation_order.front().second;
        operation_order.pop();
        
        for (int d = 0; d < 2; d++) {
            i = x + dx[d];
            j = y + dy[d];

            if (i >= row || j >= col) continue;
            if (board[i][j] == '#') continue;
            dp[i][j]+=(dp[x][y] % MOD);
            if (visited[i][j]) continue;
            visited[i][j] = true;
            operation_order.push({i,j});
        }
    }

    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout << '\n';

    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cout << dp[i][j] % MOD << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[row-1][col-1] % MOD;

    return 0;
}
