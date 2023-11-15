#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int len, element;
    vector<set<int>> list;
    set<int> courses;
    map<set<int>, int> frequence;
    int max = 0;
    int repeat_max = 1;

    cin >> len;

    while (len != 0) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> element;
                courses.insert(element);
            }
            list.push_back(courses);
            courses.clear();
        }

        for (auto k:list) {
            if (frequence.find(k) == frequence.end()) {
                frequence[k] = 1;
                // cout << "frequence: 1\n";
            }
            else {
                frequence[k]++;
                // cout << "frequence: " << frequence[k] << '\n';
            }
        }

        for (auto k:list) {
            if (frequence[k] > max) {
                max = frequence[k];
                repeat_max = 1;
            }
            else if (frequence[k] == max) {
                repeat_max++;
            }
            // cout << "max: " << max <<' ' << repeat_max << '\n';
        }

        cout << repeat_max << '\n';
        repeat_max = 0;
        max = 0;
        frequence.clear();
        list.clear();
        cin >> len;
    }
    return 0;
}