#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int packages; cin >> packages;

    priority_queue<int, vector<int>, greater<int>> order;

    int x, y;

    for (int i = 0; i < packages; i++) {
        cin >> x;

        order.push(x);

    }

    int answ = 0;

    while (order.size() != 1) {
        x = order.top(); order.pop();
        y = order.top(); order.pop();

        answ += x+y;
        order.push(x + y);
    }

    cout << answ << endl;

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}