#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int row, collumn, entrance;

    while (1) {
        cin >> row; cin >> collumn; cin >> entrance;

        if (row == 0 && collumn == 0 && entrance == 0) {
            break;
        }

        char board[row][collumn];

        for (int i = 0; i < row; i++) {
            cin.get();
            for (int j = 0; j < collumn; j++) {
                // cin >> board[i][j];
                cin.get(board[i][j]);
            }
            
        }

        // for (int i = 0; i < row; i++) {
        //     for (int j = 0; j < collumn; j++) {
        //         cout << board[i][j];
        //     }
        //     cout << '\n';
            
        // }
        
        int actual_row = 0;
        int actual_col = entrance-1;
        int steps = 0;
        bool loop = false;

        pair<int, int> cord;
        map<pair<int,int>, int> visited_cords;

        while (row > actual_row && actual_row >= 0 && collumn > actual_col && actual_col >= 0) {
            
            cord = {actual_col, actual_row};
            
            if (visited_cords.find(cord) == visited_cords.end()) {
                visited_cords[cord] = steps;
            }
            else {
                loop = true;
                break;
            }

            int cmd = board[actual_row][actual_col];

                if (cmd == 'N') {
                actual_row--;
            }
            else if (cmd == 'S') {
                actual_row++;
            }
            else if (cmd == 'E') {
                actual_col++;
            }
            else if (cmd == 'W') {
                actual_col--;
            }
            else break;
            steps++;
        }

        if (loop) {
            int beforeloop = visited_cords[cord];
            cout << beforeloop << " step(s) before a loop of " << steps-beforeloop << " step(s)\n";
        }
        else {
            cout << steps << " step(s) to exit\n";
        }
    }

    return 0;
}