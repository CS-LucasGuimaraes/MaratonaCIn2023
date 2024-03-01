#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int answ = 0;

    int n; cin >> n;

    int c = 0;

    while (n > 100) {
        
    }
    while (n>9) {
        n-=9; c++;
    }

    answ += 45*c;

    while (n > 0) {
        answ += n;
        n--;
    }

    return answ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        cout << solve() << endl;
    }

    return 0;
}





