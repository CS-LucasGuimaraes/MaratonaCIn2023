#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len;
    string str;

    cin >> len;

    for (int i = 0; i < len; i++) {
        
        int openP = 0;
        int openB = 0;
        bool valid = true;
        
        cin >> str;
        
        for (auto e:str){
            if ( e == '(' ) openP++;

            else if ( e == '[' ) openB++;

            else if ( e == ')' ) {
                if (openP == 0) {
                    valid = false;
                    break;
                }
                else {
                    openP--;
                }
            }


            else if ( e == ']' ) {
                if (openB == 0) {
                    valid = false;
                    break;
                }
                else {
                    openB--;
                }
            }


        }
        if (valid && openB==0 && openP==0) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }

    }
    


    return 0;
}