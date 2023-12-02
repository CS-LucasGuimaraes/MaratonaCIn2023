#include <bits/stdc++.h>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int controller() {

    int row, col;
    char b;
    int gcount = 0;

    cin >> row; cin >> col;

    char board[row][col];
    for (int i = 0; i < row; i++) {
        cin.get();
        for (int j = 0; j < col; j++) {
            cin.get(b);
            board[i][j] = b;
            if (b == 'G') {
                gcount++;
            }
        }
    }

    if (board[row-1][col-1] == 'B') {
        cout << "No" << '\n';
        return 0;
    }

    if (gcount == 0) {
        cout << "Yes"<< '\n';
        return 0;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'B') {
                for (int d = 0; d < 4; d++) {
                    if (i+dx[d] >= 0 && i+dx[d] < row && j+dy[d] >= 0 && j+dy[d] < col) {
                        if (board[i+dx[d]][j+dy[d]] == 'G') {
                            cout << "No" << '\n';
                            return 0;
                        }
                        if (board[i+dx[d]][j+dy[d]] == '.') board[i+dx[d]][j+dy[d]] = '#';
                    }
                }
                
            }
        }
    }

    if (board[row-1][col-1] == '#') {
        cout << "No" << '\n';
        return 0;
    }

    queue<pair<int,int>> operation_order;
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    operation_order.push({row-1,col-1});
    visited[row-1][col-1] = true;
    int x, y;
    int c = 0;

    while (!operation_order.empty()) {
        pair<int,int> cord = operation_order.front();
        operation_order.pop();

        for (int d = 0; d < 4; d++) {
            x = cord.first+dx[d]; y = cord.second+dy[d];
            if (x >= 0 && x < row && y >= 0 && y < col) {
                if (!visited[x][y]) {
                    if (board[x][y] == 'G') c++;
                    if (board[x][y] != '#') {
                        operation_order.push({x,y});
                        visited[x][y] = true;
                    }
                }
            }
        }
    }

    if (c == gcount) cout << "Yes" << '\n';
    else cout << "No" << '\n';


    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases;

    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        controller();
    }
    return 0;
}