#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases;
    string str, str2;

    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {

        deque<char> dq;

        cin >> str;
        cin >> str2;

        str += str2;

        // cout << str << '\n';

        sort(str.begin(), str.end());

        for (auto c:str) {
            if (dq.empty() == true) {
                dq.push_front(c);
            }
            else if (c < dq.front()) {
                dq.push_front(c);
            }
            else {
                dq.push_back(c);
            }
        }

        for (auto c:dq) {
            cout << c;
        }
        cout << '\n';
    }
    
    return 0;
}