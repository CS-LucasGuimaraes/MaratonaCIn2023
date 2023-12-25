#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;

    cin >> str;

    string str_lower;
    for (auto c:str) {
        char x = tolower(c);
        str_lower += x;
    }
    swap(str_lower, str);

    int size = str.size(); 
    

    if (str.find("ss") == -1) {
        cout << str;
    }

    else {

        for (int i = 0; i < size; i++) {
            if (str[i] == 's' && str[i+1] == 's') {
                cout << "B";
                i++;
            }
            else {
                cout << str[i]; 
            }
        }

        cout << '\n';
        
        for (int i = 0; i < size; i++) {
            if (str[i] == 's' && str[i+1] == 's') {
                cout << "ss";
                i++;
            }
            else {
                cout << str[i]; 
            }
        }
    }


    cout << '\n';

    if (str.find("sss") != -1) {

        for (int i = 0; i < size; i++) {
            if (str[i] == 's' && str[i+1] == 's') {
                cout << "sB";
                i+=2;
            }
            else {
                cout << str[i]; 
            }
        }

    }


    

    return 0;
}