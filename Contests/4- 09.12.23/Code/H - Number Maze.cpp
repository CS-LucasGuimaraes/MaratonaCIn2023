#include <bits/stdc++.h>

#define INF LLONG_MAX
#define int long long 

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases; cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        
        int row, col; cin >> row >> col;

        int board[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> board[i][j];
            }
        }

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> operation_order; //min heap
        vector<vector<int>> dist(row, vector<int>(col, INF));

        dist[0][0] = board[0][0];
        operation_order.push({board[0][0], {0,0}});

        while (!operation_order.empty()) {
            int len = operation_order.top().first;
            pair<int,int> out = operation_order.top().second;
            operation_order.pop();

            if (len > dist[out.first][out.second]) continue;

            for (int d = 0; d < 4; d++) {
                int x = out.first + dx[d];
                int y = out.second + dy[d];

                if (x < 0 || x >= row || y < 0 || y >= col) continue;

                int cost = board[x][y]; 
                int current_distance = dist[out.first][out.second] + cost;

                if (current_distance < dist[x][y]) {
                    dist[x][y] = current_distance;
                    operation_order.push({current_distance, {x, y}});
                }
            }
        }

        cout << dist[row-1][col-1] << '\n';

    }

    return 0;
}