#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len, start, end, start2;
    vector<bool> tv1(1000000000);
    vector<bool> tv2(1000000000);
    bool can1 = true;
    bool can2 = true;
    bool flag = true;


    cin >> len;

    for (int i = 0; i < len; i++) {
        cin >> start;
        cin >> end;
        if (flag) {
            start2 = start;
            for (start; start <= end; start++) {
                if (tv1[start] == true) {
                    can1 = false;
                }
                if (tv2[start] == true) {
                    can2 = false;
                }
            }
            if (can1) {
                for(start2; start2 <= end; start2++) {
                    tv1[start2] = true;
                }
            }

            else if (can2) {
                for(start2; start2 <= end; start2++) {
                    tv2[start2] = true;
                }
            }
            else {
                cout << "NO";
                flag = false;
            }

            can1 = true;
            can2 = true;
        }
        
    }
        if (flag) {
            cout << "YES";
        }
    return 0;
}