#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ingredients, magic_power;
    int x;

    cin >> ingredients; cin >> magic_power;

    vector<int> needed_ingredient;
    vector<int> actual_ingredient;

    for (int i = 0; i < ingredients; i++) {
        cin >> x;
        needed_ingredient.push_back(x);
    }

    for (int i = 0; i < ingredients; i++) {
        cin >> x;
        actual_ingredient.push_back(x);
    }

    ////

    int cookies = 0;

    while (1) {
        vector<bool> enough(ingredients, false);
        
        for (int i = 0; i < ingredients; i++) {
            if (actual_ingredient[i] >= needed_ingredient[i]) {
                actual_ingredient[i] -= needed_ingredient[i];
                enough[i] = true;
            }
            else {
                if (magic_power==0) break;
                while (magic_power > 0) {
                    magic_power--;
                    actual_ingredient[i]++;
                    if (actual_ingredient[i] >= needed_ingredient[i]) {
                        actual_ingredient[i] -= needed_ingredient[i];
                        enough[i] = true;
                        break;
                    }
                }
            }
        }

        for(auto e: enough) {
            if (!e) {
                cout << cookies;
                return 0;
            }
        }
        cookies++;
    }
    
    cout << cookies;
    return 0;
}