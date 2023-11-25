#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int classes, days;
    int x;
    vector<int> class_points;
    vector<int> threshold;

    cin >> classes;

    for (int i = 0; i < classes; i++) {
        cin >> x;
        class_points.push_back(x);
    }

    cin >> days;

    for (int i = 0; i < days; i++) {
        cin >> x;
        threshold.push_back(x);
    }

    for (auto i:threshold) {
        int actual = 0;
        int count = 0;
        while (actual < i) {
            actual += class_points[count];
            count++;
        }

        cout << actual << " " << count << '\n';
    }
    
    return 0;
}