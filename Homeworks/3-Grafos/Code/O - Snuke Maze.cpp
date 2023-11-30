#include <bits/stdc++.h>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, col;

    cin >> row; cin >> col;

    char board[row+2][col+2];

    for (int i = 1; i < row+1; i++) {
        cin.get();
        for (int j = 1; j < col+1; j++) {
            cin.get(board[i][j]);
        }
    }

    stack<pair<int,int>> operation_order;
    pair<int,int> cord;
    vector<vector<bool>> visited(row+2, vector<bool>(col+2, false));
    char expected_order[6] = {'s','n','u','k','e','s'};
    vector<vector<int>> expected(row+2, vector<int>(col+2));

    if (board[1][1] == 's') {
        operation_order.push({1,1});
        // visited[1][1] = true;
        expected[1][1] = 0;
    }

    while(!operation_order.empty()) {
        
        int i = operation_order.top().first;
        int j = operation_order.top().second;
        operation_order.pop();
        visited[i][j] = true;


        for (int a = 0; a < 4; a++) {
            if (!visited[i+dx[a]][j+dy[a]]) {
                if (board[i+dx[a]][j+dy[a]] == expected_order[expected[i][j]+1]) {
                    operation_order.push({i+dx[a],j+dy[a]});
                    expected[i+dx[a]][j+dy[a]] = expected[i][j] + 1;
                    if (expected[i+dx[a]][j+dy[a]] == 5) expected[i+dx[a]][j+dy[a]] = 0; 
                    visited[i+dx[a]][j+dy[a]] = true;
                }
            }
        }
    }

    if (visited[row][col]) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}