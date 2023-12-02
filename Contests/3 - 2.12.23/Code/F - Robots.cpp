#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases;

    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        
        int row, col;

        cin >> row; cin >> col;

        // char board[row][col];
        char x;

        vector<int> top, lft; 
        // vetor<int> bot,  rgt;
        int mintop = row , minlft = col;
        // int minbot = 6, minrgt=6;

        for (int i = 0; i < row; i++) {
            cin.get();
            for (int j = 0; j < col; j++) {
                cin.get(x);
                
                if (x == 'R') {
                    top.push_back(i);
                    // bot.push_back(row - i-1);
                    lft.push_back(j);
                    // rgt.push_back(col - j-1);

                    if (i < mintop) mintop = i;
                    // if (row-i-1 < minbot) minbot = row-i-1;
                    if (j < minlft) minlft = j;
                    // if (col-j-1 < minrgt) minrgt = col-j-1;
                }
            }
        }

        int len = top.size();

        bool bp = false;

        for (int i = 0; i < len; i++) {
            if (mintop >= top[i] && minlft >= lft[i]) {
                cout << "YES" << '\n';
                bp  = true;
                break;
            }
        }

        if (!bp) {
            cout << "NO" << '\n';
        }
        

    }
    

    return 0;
}