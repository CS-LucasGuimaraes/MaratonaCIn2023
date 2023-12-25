#include <bits/stdc++.h>

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

#define int long long

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases;

    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        
        int row, collumn;
        int x;

        cin >> row; cin >> collumn;

        int board[row][collumn];

        vector<vector<bool>> visited_cords(row, vector<bool>(collumn, false)); //bool matriz[i][j] com construtor para todos os elementos serem false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < collumn; j++) {
                cin >> x;  
                board[i][j] = x; 
                if (x == 0) {
                    visited_cords[i][j] = true;
                }
            }
        }
        int maxlake = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j=0; j < collumn; j++) {
                if(!visited_cords[i][j]) {
                    int actual_row;
                    int actual_col;
                    
                    queue<pair<int,int>> operation_order;
                    pair<int,int> cord;
                    int cont = 0;

                    operation_order.push({i,j});
                    visited_cords[i][j] = true;            

                    while (!operation_order.empty()) {
                        cord = operation_order.front();
                        operation_order.pop();
                        actual_row = cord.first;
                        actual_col = cord.second;
                        cont+=board[actual_row][actual_col];

                        for (int d = 0; d < 4; d++) {
                            int ax = actual_row + dx[d];
                            int ay = actual_col + dy[d];

                            if(ax >= 0 && ax < row && ay >=  0 && ay < collumn && visited_cords[ax][ay] == false) {
                                operation_order.push({ax,ay});
                                visited_cords[ax][ay] = true;
                            }
                        }
                    }
                    if (cont > maxlake) maxlake = cont;
                }   

            }
        }
        cout << maxlake << '\n';
    }

    return 0;
}