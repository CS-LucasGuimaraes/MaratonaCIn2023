#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> answ;

    int n; cin >> n;

    vector<bool> respect(n+1);
    vector<int> parent(n+1);
    vector<vector<int>> children(n+1);

    int x; 
    bool b;

    for (int i = 1; i <= n; i++) {
        cin >> x >> b;

        parent[i] = x;
        respect[i] = b;
        if (x != -1) children[x].push_back(i); 
    }

    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) continue;

        bool impossible = false;
        if (respect[i]) {
            for (auto e: children[i]) {
                if (!respect[e]) {
                    impossible = true;
                    break;
                }
            }
            if (!impossible) {
                answ.push_back(i);
                for (auto e: children[i]) {
                    parent[e] = parent[i];
                }   
            }
        }

    }
    if (answ.size() == 0) cout << -1;

    for (auto e: answ) {
        cout << e << ' ';
    }
    cout << endl;
    

    return 0;
}