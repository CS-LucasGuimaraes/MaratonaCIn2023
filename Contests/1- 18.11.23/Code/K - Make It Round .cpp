#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len;

    cin >> len;

    for (int i = 0; i < len; i++) {
        int x;
        int y;

        cin >> x;
        cin >> y;

        int n5 = 0;
        int n2 = 0;
        int x5, x2, yo;

        yo = y;
        x5 = x; 
        x2 = x;

        while (x5%5==0) {
            x5/=5;
            n5++;
        }
        while (x2%2==0) {
            x2/=2;
            n2++;
        }

        int count = 0;
        while (y>10) {
            y/=10;
            count++;
        }

        if (y == 2) n2--;
        if (y == 5) n5--;

        if (n2 == n5) {            
            cout << x*y*pow(10,count);
        }
        else if (n2 > n5) {
            cout << x*pow(10,count-1)*y*(2*(n2 - n5));
        }
        
        else if (n5 > n2) {
            cout << x*pow(10,count-1)*y*(5*(n5 - n2));
        }   
    }
    

    return 0;
}