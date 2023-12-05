#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cities; cin >> cities; 

    int n= cities+1;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int x;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int roads; cin >> roads;
    
    int y, len; // int x previous declaration

    ll sum = 0;

    for (int i = 0; i < roads; i++) {
        cin >> x >> y >> len;

        if (len > matrix[x][y]) {

            if (sum == 0) {
                for (int i = 1; i < n; i++) {
                    for (int j = 1; j < n; j++) {
                        if (i >= j) continue;

                        sum+= matrix[i][j];
                    }
                }
            }

            cout << sum << " ";
            continue;
        }

        matrix[x][y] = len; 
        matrix[y][x] = len;

        int k;
        // for (int k = 1; k < n; k++) { // o valor de K só pode ser x ou y
        for (int m = 0; m < 2; m++) {
            if (m == 0) k = x;
            else k = y; 
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                }   
            }
        }

        sum = 0;

        for (int i = 1; i < n; i++) {
            for (int j = i+1; j < n; j++) {

                sum += matrix[i][j];
            }
        }
        cout << sum << " ";
    
    }

    return 0;
}