#include <bits/stdc++.h>

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col;
    char x;

    cin >> row; cin >> col;

    // char board[row][col];

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(x);
            // board[i][j] = x;

            if (x=='.') {
                visited[i][j] = true;
            }
        }
    }

    int cont = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!visited[i][j]) {
                int actual_row, actual_col;

                queue<pair<int,int>> operation_order;
                pair<int,int> cord;

                operation_order.push({i,j});
                visited[i][j] = true;

                while(!operation_order.empty()) {
                    cord = operation_order.front();
                    operation_order.pop();
                    actual_row = cord.first;
                    actual_col = cord.second;

                    for (int d = 0; d < 4; d++) {
                        int ax = actual_row + dx[d];
                        int ay = actual_col + dy[d];

                        if (ax >= 0 && ax < row
                         && ay >= 0 && ay < col
                         && visited[ax][ay] == false) {
                            operation_order.push({ax,ay});
                            visited[ax][ay] = true;
                        }
                    }

                }
                cont++;
            }
        }
        
    }
    
    cout << cont;
    

    return 0;
}