#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str; cin >> str;
    stack<char> stk;

    for (auto x: str) {
        if (stk.empty()) stk.push(x);
        else if (stk.top() == x) stk.pop();
        else stk.push(x);
    }

    if (stk.empty()) cout << "Yes";
    else cout << "No";

    return 0;
}