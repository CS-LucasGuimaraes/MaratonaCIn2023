#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char cha;
    int n; cin >> n; cin.get();
    int a=0; int c=0; int g=0; int t=0; int q=0;
    vector<char> string;

    for (int i = 0; i < n; i++) {
        cin.get(cha);

             if (cha == 'A') a++; 
        else if (cha == 'C') c++; 
        else if (cha == 'G') g++; 
        else if (cha == 'T') t++; 
        else if (cha == '?') q++;

        string.push_back(cha); 
    }

    int m = max(max(a,c),max(g,t));
    int ra = (m-a), rc = (m-c), rg = (m-g), rt = (m-t);
    int r = ra+rc+rg+rt;

    if (((q-r) % 4 != 0) || (a > n/4 || c > n/4 || g > n/4 || t > n/4)) {
        cout << "===" << endl;
        return 0;
    }

    for (auto e: string) {
        if (e == '?') {
                 if (ra){
                cout << 'A';
                ra--;
            }

            else if (rc){
                cout << 'C';
                rc--;
            }
            
            else if (rg){
                cout << 'G';
                rg--;
            }
            
            else if (rt){
                cout << 'T';
                rt--;
            }
            else {
                cout << 'A';
                rc++; rg++; rt++;
            }
        }
        else cout << e;
    }

    return 0;
}