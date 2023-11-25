#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    vector<int> square, perfect;
    int int_sqrt;
    double float_sqrt;

    cin >> a; cin >> b;

    for (1; a <= b; a++) {
        if (square.empty() == true) {

            int_sqrt = sqrt(a);
            float_sqrt = sqrt(a);

            if (int_sqrt == float_sqrt) {
                square.push_back(a);
            }
        }
        else {
            break;
        }
    }

    int x = sqrt(a);

    while (x*x < b) {
        x++;
        square.push_back(x*x);
    }

    for (auto c:square) {
        string str = to_string(c);
        reverse(str.begin(), str.end());
        int k = stoll(str);

        int_sqrt = sqrt(k);
        float_sqrt = sqrt(k);

        if (int_sqrt == float_sqrt && c%10!=0) {
            perfect.push_back(c);
        }
    }

    // for (auto c:perfect) {
    //     cout << c << '\n';
    // }
    cout << perfect.size();

    return 0;
}