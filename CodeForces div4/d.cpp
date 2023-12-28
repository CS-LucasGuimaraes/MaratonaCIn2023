#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        int len; cin >> len;
        string s; cin >> s;

        string answ;

        while (!s.empty()) {
            if (s.back() == 'b' || s.back() == 'c' || s.back() == 'd') {
                answ += s.back(); s.pop_back();
                answ += s.back(); s.pop_back();
                answ += s.back(); s.pop_back();
                answ += '.';
            }
            else {
                answ += s.back(); s.pop_back();
                answ += s.back(); s.pop_back();
                answ += '.';                
            }
        }
        answ.pop_back();
        reverse(answ.begin(), answ.end());
        cout << answ << endl;
    }

    return 0;
}