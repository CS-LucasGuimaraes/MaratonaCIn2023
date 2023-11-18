#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    int put = 0;
    cin >> x;

    while (x!=0) {
        // cout << x << " ";
        if (x%2 == 0) {
            x /= 2;
        }
        else {
            x -= 1;
            put += 1;
        }
    }

    cout << put;

    return 0;
}