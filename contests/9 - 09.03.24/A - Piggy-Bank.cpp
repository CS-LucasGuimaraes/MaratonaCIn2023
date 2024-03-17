#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
#define int long long
using ll = long long;
using pii = pair<int,int>;

struct item {
    int weight;
    int value;
};

const int max_coins = 1e4+1;
const int INF = INT_MAX;

int solve() {

    int empty, full; cin >> empty >> full;
    int coins; cin >> coins;
    vector<item> items = {{0,0}};
    vector<vector<int>> table(max_coins, vector<int>(++full, INF));


    for (int i = 0; i < coins; i++) {
        int value, weight; cin >> value >> weight;

        items.push_back({weight, value});
    }

    // for (int i = 0; i < max_coins;i++) { // setting the capacity 0 to INF value;
    //     table[i][0] = INF;
    // }
    // for (int j = 0; j < full; j++) { // setting the item 0 to INF value;
    //     table[0][j] = INF;
    // }
    
    table[1][items[1].weight] = items[1].value; 

    for (int i = 1; i < items.size(); i++) { // populating the table;
        for (int j = 1; j < full; j++) {
            int w = items[i].weight;
            int v = items[i].value;
            
            table[i][j] = min(table[i][j], table[i-1][j]);
            if (w <= j) table[i][j] = min(table[i][j], table[i-1][j-w]+v);
        }
    }

    for (int i = 0; i < items.size(); i++) { // printing the table for debug
        cout << '\n';
        for (int j = 0; j < full; j++) {
            if (table[i][j] < 10000) cout << table[i][j] << ' ';
            else cout << '- ';
        }
    }
    cout << '\n';        

    cout << table[items.size()-1][--full] << '\n';

    return 0;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}