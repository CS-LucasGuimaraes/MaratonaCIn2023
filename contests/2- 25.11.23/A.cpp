#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;


    int test_cases;
    int x1, x2, y1, y2;

    cin >> test_cases;

    for (int loop = 0; loop < test_cases; loop++) {
        cin >> x1; cin >> y1;
        cin >> x2; cin >> y2;

        double a, b;


        int i = y1-y2;
        int j = x1+x2;
        int k = x1-x2;

        b = ((k*j*y1) - i ) / ((x1*k*j) - k);
        a = ((i / (k*j)) - (b / j));

        double resultado = (b*(-1)) / a;

        cout << a << " " << b << '\n';
        cout << resultado << '\n';

    }
    


    return 0;
}