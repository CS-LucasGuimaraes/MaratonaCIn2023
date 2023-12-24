#include <bits/stdc++.h>

#define endl '\n'

using ll = long long;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int budget, party_count;

        cin >> budget >> party_count;

        if (budget == 0 && party_count == 0) return 0; // break on 0 0;

        int table[++party_count][++budget];

        int fee;
        int fun;

        vector<pair<int,int>> parties = {{0,0}};

        for (int i = 1; i < party_count; i++) { // reading the parties
            cin >> fee >> fun;

            parties.push_back({fee, fun});
        }

        for (int i = 0; i < party_count;i++) { // setting the budget 0 to 0 fun;
            table[i][0] = 0;
        }
        for (int j = 0; j < budget; j++) { // setting the party 0 to 0 fun;
            table[0][j] = 0;
        }

        for (int i = 1; i < party_count; i++) { // populating the table;
            for (int j = 1; j < budget; j++) {
                int w = parties[i].first;
                int v = parties[i].second;
                
                table[i][j] = table[i-1][j];
                if (w <= j) table[i][j] = max(table[i][j], v + table[i-1][j-w]);
            }
        }

        // for (int i = 0; i < party_count; i++) { // printing the table for debug
        //     cout << endl;
        //     for (int j = 0; j < budget; j++) {
        //         cout << table[i][j] << ' ';
        //     }
        // }
        // cout << endl;

        int minbudget = 0; //retrieving the best budget 
        for(int i=0; i < budget; i++) {// from which col do I get the best result?
            if(table[party_count-1][i] == table[party_count-1][budget-1]) {
                minbudget = i;
                break;
            }
        }

        cout << minbudget << ' '; // print the price;
        cout << table[--party_count][--budget] << endl; //print the max fun;

    }
    
    return 0;
}