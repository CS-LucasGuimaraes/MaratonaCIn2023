#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col; char c;
    
    cin >> row >> col;
    
    char board[row][col];
    
    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; i++) {
            cin.get(c);
            board[i][j] = c;
        }
    }

    return 0;
}