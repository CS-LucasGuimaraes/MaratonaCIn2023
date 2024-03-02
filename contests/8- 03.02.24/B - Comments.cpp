#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<vector<string>> comments(1e6);
int max_depth = 1;

int solve(int depth=1) {
    string str;
    string childs_string;
    int childs;
    max_depth = max(max_depth, depth);
        
    if (!(getline(cin, str, ','))) return 0;
    getline(cin, childs_string, ',');
    childs = stoi(childs_string);

    comments[depth].push_back(str);

    for (int i = 0; i < childs; i++) {
        solve(depth+1);
    }

    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (solve());
    
    cout << max_depth << endl;
    for (int i = 1; i <= max_depth; i++) {
        for (auto e: comments[i])
            cout << e << ' ';
        cout << endl; 
    }
    

    return 0;
}