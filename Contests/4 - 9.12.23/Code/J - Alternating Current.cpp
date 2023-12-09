#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str; cin >> str;
    int c;

    int n = str.size();

    while (n > 0) {
        c = 0;
        
        if (str.find("++") != str.npos) {
            int i = str.find("++");
            str[i] = 0; str[i+1] = 0;
            c++;
            n-=2;
        }
        if (str.find("--") != str.npos) {
            int i = str.find("--");
            str[i] = 0; str[i+1] = 0;
            c++;
            n-=2;
        }

        if (c == 0) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}