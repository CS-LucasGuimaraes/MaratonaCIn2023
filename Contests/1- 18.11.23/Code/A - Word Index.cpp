#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    int value;


    while(cin >> str) {
        deque<int> str_ascci;
        int x;
        bool invalid = false;


        for (auto c:str) {
            x = c -96;
            if (str_ascci.empty() == true) {
                str_ascci.push_back(x);
            }
            else if (str_ascci.empty() == false) { 
                if (str_ascci.front() < x) {
                    str_ascci.push_back(x);
                }
                else {
                    value = 0;
                    invalid = true;
                    break;
                }
            }
        }

        if (!invalid) {

        }
        cout << value << '\n';
    }

    return 0;
}