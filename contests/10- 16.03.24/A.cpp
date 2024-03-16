#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<string>> board1(5, vector<string>(5));
    char x;
    
    vector<string> V;
    vector<string> A;
    vector<string> N;
    vector<string> E;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board1[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        cin.get();
        for (int j = 0; j < 5; j++) {
            cin.get(x);

                 if (x == 'V') V.push_back(board1[i][j]);
            else if (x == 'A') A.push_back(board1[i][j]);
            else if (x == 'N') N.push_back(board1[i][j]);
            else if (x == 'E') E.push_back(board1[i][j]);
        }
    }

    sort(V.begin(), V.end());
    sort(A.begin(), A.end());
    sort(N.begin(), N.end());
    sort(E.begin(), E.end());

    for (auto e: V) cout << e << ' ';
    cout << endl; 
    for (auto e: A) cout << e << ' ';
    cout << endl; 
    for (auto e: N) cout << e << ' ';
    cout << endl; 
    for (auto e: E) cout << e << ' ';
    cout << endl; 
    

    return 0;
}