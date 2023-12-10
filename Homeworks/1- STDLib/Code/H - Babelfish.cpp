#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, string> dict;
    string str, key, value;


    getline(cin, str);
    
    while (str.empty() == false) {
        stringstream strcpy (str);
        while (getline(strcpy, value, ' ')) {
            getline(strcpy, key, ' '); 
            dict[key] = value;
        }
        getline(cin, str);
    }

    getline(cin, key);

    while (key.empty() == false) {
        if (dict[key].empty() == false) cout << dict[key] << '\n';
        else cout << "eh" << '\n';
        getline(cin, key);
    }

    return 0;
}