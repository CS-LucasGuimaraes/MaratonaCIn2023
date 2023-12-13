#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int coins, sum;
    cin >> coins >> sum;

    int coin;

    vector<int> values;

    for (int i = 0; i < coins; i++) {
        cin >> coin;

        values.push_back(coin);
    }

    sort(values.begin(), values.end());



    cout << 1%(10e9+7);

    return 0;
}