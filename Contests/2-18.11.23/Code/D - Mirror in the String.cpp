#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len, len2;

    cin >> len;

    for (int i = 0; i < len; i++) {
        
        char c;
        int x;
        deque<int> dq;
        deque<int> dq2;
        bool stop = false;


        cin >> len2;
        for (int j = 0; j < len2; j++) {
            cin >> c;
            x = c;
            // cout << x << " ";
            if (dq.empty() == true) {
                dq.push_front(x);
                dq2.push_front(x);
            }
            else if (!stop && dq.front()>=x) {
                dq.push_front(x);
                dq2.push_front(x);
            }
            else {
                stop = true;
            }
        }

        while (dq.empty() == false) {
            c = dq.back();            
            cout << c;
            dq.pop_back();
        }

        while (dq2.empty() == false) {
            c = dq2.front();            
            cout << c;
            dq2.pop_front();
        }

        cout << '\n';

    }

    return 0;
}