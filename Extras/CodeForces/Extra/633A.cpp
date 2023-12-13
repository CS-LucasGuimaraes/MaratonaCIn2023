#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;

    cin >> a >> b >> c;
    
    int s = c;

    while (c >= b) {
        c-=b;
        if (c % a == 0 || c == b) {
            cout << "Yes";
            return 0;
        }
    }

    c = s;

    while (c >= a) {
        c-=a;
        if (c % b == 0 || c == a) {
            cout << "Yes";
            return 0;
        }
    }

    if (c != 0) cout << "No";

    return 0;
}