#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

string solve() {

    int n; cin >> n;

    vector<vector<char>> board(n, vector<char>(n));

    char b;

    for (int i = 0; i < n; i++) {
        cin.get();
        for (int j = 0; j < n; j++) {
            cin.get(b);
            board[i][j] = b;
        }
    }
    
    int k = 0;

    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '1') c++;
        }
        if (k!=0 && k == c) return "SQUARE";
        if (c != 0) k = c;
        
    }
    

    return "TRIANGLE";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        cout << solve() << endl;
    }

    return 0;
}