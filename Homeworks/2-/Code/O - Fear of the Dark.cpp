#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;

    int len;

    cin >> len;

    int Xo = 0;
    int Yo = 0;

    for (int i = 0; i < len; i++) {
        int Xp, Yp, Xa, Ya, Xb, Yb;

        cin >> Xp;
        cin >> Yp;

        cin >> Xa;
        cin >> Ya;

        cin >> Xb;
        cin >> Yb;
    
        double Dap, Dao;
        double Dbp, Dbo;

        Dap = pow((pow((Xp - Xa), 2) + pow((Yp - Ya), 2)), 0.5);
        Dao = pow((pow((Xo - Xa), 2) + pow((Yo - Ya), 2)), 0.5);

        Dbp = pow((pow((Xp - Xb), 2) + pow((Yp - Yb), 2)), 0.5);
        Dbo = pow((pow((Xo - Xb), 2) + pow((Yo - Yb), 2)), 0.5);

        double r_case1 = min(max(Dap, Dao), max(Dbp, Dbo));
    

        double Dab;
        Dab = pow((pow((Xb - Xa), 2) + pow((Yb - Ya), 2)), 0.5);
    
        double r_case2 = Dab/2;

        if ((r_case2 < r_case1) && ((r_case2 >= Dbp || r_case2 >= Dap) && (r_case2 >= Dao || r_case2 >= Dbo))) {
            cout << r_case2 << '\n';    
        }
        else {
            cout << r_case1 << '\n';
        }   

    }
    return 0;
}