#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; char c;
    
    cin >> n;
    
    char board[n][n];
    
    for (int i = 0; i < n; i++) {
        cin.get();
        for (int j = 0; j < n; i++) {
            cin.get(c);
            board[i][j] = c;
        }
    }

    return 0;
}