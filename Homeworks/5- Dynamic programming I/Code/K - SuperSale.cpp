#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct item {
    int weight;
      ll value;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases; cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {

        int item_count;

        cin >> item_count;

        ll  value;
        int weight;

        vector<item> items = {{0,0}};

        for (int i = 0; i < item_count; i++) { // reading the items
            cin >> value >> weight;

            items.push_back({weight, value});
        }

        int people; cin >> people;

        int sum = 0;

        for (int pp = 0; pp < people; pp++) {

            int capacity; cin >> capacity;

            ll table[++item_count][++capacity];

            for (int i = 0; i < item_count;i++) { // setting the capacity 0 to 0 value;
                table[i][0] = 0;
            }
            for (int j = 0; j < capacity; j++) { // setting the item 0 to 0 value;
                table[0][j] = 0;
            }

            for (int i = 1; i < item_count; i++) { // populating the table;
                for (int j = 1; j < capacity; j++) {
                    int w = items[i].weight;
                    ll v = items[i].value;
                    
                    table[i][j] = table[i-1][j];
                    if (w <= j) table[i][j] = max(table[i][j], v + table[i-1][j-w]);
                }
            }

            // for (int i = 0; i < item_count; i++) { // printing the table for debug
            //     cout << '\n';
            //     for (int j = 0; j < capacity; j++) {
            //         cout << table[i][j] << ' ';
            //     }
            // }
            // cout << '\n';

            sum += table[--item_count][--capacity];
        }

        cout << sum << '\n';
        
    }

    return 0;
}