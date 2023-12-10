#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len, len2;
    cin >> len;

    for (int i = 0; i < len; i++) {
        int prod = 1;
        string item, category;
        vector<string> vec;
        map<string, int> frequence;

        cin >> len2;
        for (int j = 0; j < len2; j++)
        {
            cin >> item;
            cin >> category;

            vec.push_back(category);
        }
        for (auto k:vec) {
            if (frequence.find(k) == frequence.end()) {
                frequence[k] = 2;
            }
            else {
                frequence[k]++;
            }
        }
        
        for (map<string, int>::iterator k = frequence.begin(); k != frequence.end(); k++) {
            prod *= (*k).second;
            // cout << "freq: " << (*k).second << '\n';
        }
        cout << prod-1 <<'\n';
    }
    
    return 0;
}