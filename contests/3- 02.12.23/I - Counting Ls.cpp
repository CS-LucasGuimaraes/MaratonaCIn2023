#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    char b;

    cin >> n;

    char board[n][n];

    for (int i = 0; i < n; i++) {
        cin.get();
        for (int j = 0; j < n; i++) {
            cin.get(b);
            board[i][j] = b;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; i++) {
            board[i][j];
        }
    }

    
    

    return 0;
}