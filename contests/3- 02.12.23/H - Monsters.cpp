    #include <bits/stdc++.h>

    using namespace std;

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    char board[1001][1001];

    bool monster_bfs(pair<int,int> monster, int row, int col, pair<int,int> objective, int objective_distance) {
        
        queue<pair<int,int>> operation_order;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> distance(row, vector<int>(col, 0));

        int x,y;

            operation_order.push(monster);
            visited[monster.first][monster.second] = true;
            while(!operation_order.empty()) {
                pair<int,int> cord = operation_order.front();
                operation_order.pop();

                for (int d = 0; d < 4; d++) {
                    x = cord.first+dx[d]; y = cord.second+dy[d];

                    if (!visited[x][y]) {
                        if (x == objective.first && y == objective.second) {
                            if (distance[cord.first][cord.second] + 1 <= objective_distance) {
                                return false;
                            }
                            else return true;
                        }
                        else if (board[x][y] == '.') {
                            operation_order.push({x,y});
                            visited[x][y] = true;
                            distance[x][y] = distance[cord.first][cord.second] + 1;
                        }
                    }
                }
            }
            
        return true;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);

        int row, col;
        char b;
        vector<pair<int,int>> monsters;
        pair<int,int> start;

        cin >> row; cin >> col;


        for (int i = 0; i < row; i++) {
            cin.get();
            for (int j = 0; j < col; j++) {
                cin.get(b);
                board[i][j] = b;

                if (b == 'A') {
                    start = {i,j};
                }

                if (b == 'M') {
                    monsters.push_back({i,j});
                }
            }
        }

        queue<pair<int,int>> operation_order;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> distance(row, vector<int>(col, 0));

        int x,y;
        
        vector<pair<int,int>> objective;
        vector<int> objective_distance;

        operation_order.push(start);
        visited[start.first][start.second] = true;
        while(!operation_order.empty()) {
            pair<int,int> cord = operation_order.front();
            operation_order.pop();

            for (int d = 0; d < 4; d++) {
                x = cord.first+dx[d]; y = cord.second+dy[d];

                if (!visited[x][y]){
                    if (x == col-1 || x == 0) {
                        if ((y == row-1 || y == 0)) {
                            objective.push_back({x,y});
                            objective_distance.push_back(distance[cord.first][cord.second] + 1);
                        }
                    }
                    else if (board[x][y] == '.') {
                        operation_order.push({x,y});
                        visited[x][y] = true;
                        distance[x][y] = distance[cord.first][cord.second] + 1;
                    }
                }
            }
        }

        vector<bool> possible(monsters.size(), false);

        int o_size = objective.size();
        for (int i = 0; i < o_size; i++) {
            bool run = true;
            for (auto e: monsters) {
                possible.push_back(monster_bfs(e, row, col, objective[i], objective_distance[i]));
            }
            for (auto e: possible) {
                if (!e) {
                    run = false;
                    break;
                }
            }
            if  (run) {
                cout << "YES";
                return 0;
            }
        }

        cout << "NO";
        return 0;
    }