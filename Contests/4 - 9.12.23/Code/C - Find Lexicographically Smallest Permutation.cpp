#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases; cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        int numbers, operations; cin >> numbers >> operations;

        vector<int> list;

        int x, y;

        for (int i = 0; i < numbers; i++) {
            cin >> x;

            list.push_back(x);
        }

        vector<pair<int,int>> in_operations;

        for (int i = 0; i < operations; i++) {
            cin >> x >> y;

            in_operations.push_back({--x, --y});
        }

        vector<int> list2 = {};

        while (list2 != list) {
            list2 = list;
            for (auto e:in_operations) {
                x = e.first; y = e.second;
                if (list[y] < list[x]) swap(list[y], list[x]);
            }
        }

        for (auto e: list) {
            cout << e << " ";
        } 
        
        cout << '\n';
        
    }
    

    return 0;
}