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

        char x;

        vector<int> top, lft; 
        int mintop = row , minlft = col;

        for (int i = 0; i < row; i++) {
            cin.get();
            for (int j = 0; j < col; j++) {
                cin.get(x);
                
                if (x == 'R') {
                    top.push_back(i);
                    lft.push_back(j);

                    if (i < mintop) mintop = i;
                    if (j < minlft) minlft = j;
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