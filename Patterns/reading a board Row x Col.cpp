#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col;
    char b;

    cin >> row; cin >> col;

    char board[row][col];

    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; i++) {
            cin.get(b);
            board[i][j] = b;
        }
    }
    

    return 0;
}