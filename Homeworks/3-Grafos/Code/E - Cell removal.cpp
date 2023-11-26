#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int size;
    char x;

    cin >> size;
    
    char board[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> x;
            board[i][j] = x;
        }
        
    }
    
    int actual_i, actual_j;

    cin >> actual_i; cin >> actual_j;
    pair<int,int> actual_cord = {actual_i-1, actual_j-1};
    queue<pair<int,int>> qe;
    map<pair<int,int>, bool> visited;
    int count = 1;

    qe.push(actual_cord);
    visited[actual_cord] = true;
    while (!qe.empty()) {
        actual_cord = qe.front();
        actual_i = actual_cord.first;
        actual_j = actual_cord.second;
        qe.pop();

        int j = 0;
        for (int i = -1; i <= 1; i+=2) {
            if (board[actual_i+i][actual_j+j] == '.' && !visited[{actual_i+i,actual_j+j}]) {
                qe.push({actual_i+i,actual_j+j});
                visited[{actual_i+i,actual_j+j}] = true;
                count++;
            }
        }
        int i = 0;
        for (int j = -1; j <= 1; j+=2) {
            if (board[actual_i+i][actual_j+j] == '.' && !visited[{actual_i+i,actual_j+j}]) {
                qe.push({actual_i+i,actual_j+j});
                visited[{actual_i+i,actual_j+j}] = true;
                count++;
            }
        }
    }

    cout << count;

    return 0;
}