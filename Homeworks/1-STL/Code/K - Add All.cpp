#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len, x;

    cin >> len;

    while (len != 0) {
        int cost = 0;
        deque<int> dq;
        
        for (int i = 0; i < len; i++) {
            cin >> x;
            dq.push_front(x);
        }
        sort(dq.begin(), dq.end());

        int size = dq.size();
        for (int j = 0; j < size - 1; j++) {
            x = dq.front();
            dq.pop_front();
            x += dq.front();
            dq.pop_front();
            dq.push_front(x);
            cost += x;
            sort(dq.begin(), dq.end());
        }
        
        cout << cost << '\n';
        cin >> len;
    }
    return 0;
}