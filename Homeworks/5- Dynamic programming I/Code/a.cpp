#include <bits/stdc++.h>

#define ll long long

using namespace std;

// struct party {
//     int fee;
//       ll fun;
// };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int budget, party_count;

        cin >> budget >> party_count;

        if (budget == 0 && party_count == 0) return 0;

        ll table[++party_count][++budget];

        int fee;
        ll  fun;

        vector<pair<int,int>> parties = {{0,0}};

        for (int i = 1; i < party_count; i++) { // reading the parties
            cin >> fee >> fun;

            parties.push_back({fee, fun});
        }

        sort(parties.begin(), parties.end());

        for (int i = 0; i < party_count;i++) { // setting the budget 0 to 0 fun;
            table[i][0] = 0;
        }
        for (int j = 0; j < budget; j++) { // setting the party 0 to 0 fun;
            table[0][j] = 0;
        }

        for (int i = 1; i < party_count; i++) { // populating the table;
            for (int j = 1; j < budget; j++) {
                int w = parties[i].first;
                ll v = parties[i].second;
                
                table[i][j] = table[i-1][j];
                if (w <= j) table[i][j] = max(table[i][j], v + table[i-1][j-w]);
            }
        }

        vector<int> chosen_itens; // retrieving the chosen itens in the optimal solution
        int c = budget - 1;
        for (int i = party_count - 1; i > 0; i--) {
            if (table[i][c] != table[i-1][c]) {
                chosen_itens.push_back(i);
                c -= parties[i].first;
            }
        }

        // for (int i = 0; i < party_count; i++) { // printing the table for debug
        //     cout << '\n';
        //     for (int j = 0; j < budget; j++) {
        //         cout << table[i][j] << ' ';
        //     }
        // }
        // cout << '\n';


        int sum = 0;
        for (auto e: chosen_itens) sum += parties[e].first; //getting the price sum;

        cout << sum << ' '; // print the price;
        cout << table[--party_count][--budget] << '\n'; //print the max fun;

    }
    
    return 0;
}