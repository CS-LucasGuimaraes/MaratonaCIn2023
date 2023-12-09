#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int notifications; cin >> notifications;

    int time, duration;

    int actual_time = 0;

    for (int i = 0; i < notifications; i++) {
        cin >> time >> duration;

        if (time - actual_time > 0) actual_time = time + duration;
        else actual_time += duration;

    }

    cout << actual_time;
    

    return 0;
}