#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int size_t, target;
    int x;

    cin >> size_t; cin >> target;
    
    vector<int> possible_values;

    for (int i = 0; i < size_t; i++) {
        cin >> x;
        if (x < target-2) {
            possible_values.push_back(x);
        }
    }

    sort(possible_values.begin(), possible_values.end());

    int size = possible_values.size();

    for (int i = 0; i < size; i++) {
        if (possible_values[i] > target) break;

        for (int j = 0; j < size; j++) {
            if (possible_values[j] > target-possible_values[i]) break;
            if (j==i) continue;

            for (int k = 0; k < size; k++) {
                if (possible_values[k] > target-possible_values[i]-possible_values[k]) break;
                if (k==1) continue; if (k == j) continue;

                if (possible_values[k] + possible_values[j] + possible_values[i] == target) {
                    cout << i+1 << " " << j+1 << " " << k+1;
                    return 0; 
                }
            }
            
        }
        
    }
    
    cout << "IMPOSSIBLE";

    return 0;
}