#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> divisors;

    divisors.push_back(1);

    for (int i = 2; i <= 9; i++) {
        if (n % i == 0) 
            divisors.push_back(i);
    }

    int flag = 1;
    cout << 1;
    for (int i = 1; i <= n; i++) {
        flag = 1;
        for (auto e: divisors) {
            if ((n/e) <= i) {
                if (i%(n/e)==0) {
                    cout << e;
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) cout << '-';
    }    
    

    return 0;
}