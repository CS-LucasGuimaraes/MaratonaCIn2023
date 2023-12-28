#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        char c;
    
        char board[3][3];
        
        int x, y;

        for (int i = 0; i < 3; i++) {
            cin.get();
            for (int j = 0; j < 3; j++) {
                cin.get(c);
                board[i][j] = c;
                if (c == '?') {
                    x = i;
                    y = j;
                }
            }
        }

        vector<char> already; 

        if (x != 0) {
            already.push_back(board[0][y]);
        }
        if (x != 1) {
            already.push_back(board[1][y]); 
        }
        if (x != 2) {
            already.push_back(board[2][y]);
        }

        if ('A' != already[0] && 'A' != already[1]) cout << "A" << endl;
        else if ('B' != already[0] && 'B' != already[1]) cout << "B" << endl;
        else if ('C' != already[0] && 'C' != already[1]) cout << "C" << endl;
    }

    return 0;
}