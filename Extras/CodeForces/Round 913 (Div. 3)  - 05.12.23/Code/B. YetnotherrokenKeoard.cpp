#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases; cin >> test_cases; cin.get();

    for (int tc = 0; tc < test_cases; tc++) {
        char x;

        vector<char> upper;
        vector<char> lower;
        

        cin.get(x);
        while (x != '\n') {
            int c = 0;

            if (int(x)== 66) { // B
                if(!upper.empty()) {
                    while(upper.back() == '0' && !upper.empty()) {
                        c++;
                        upper.pop_back();
                    }
                    if (!upper.empty()) {
                        upper.pop_back();
                        c++;
                    }   
                    for (int i = 0; i < c; i++) {
                        upper.push_back('0');
                    }   
                }
            }

            else if (int(x)== 98) { // b
                if(!lower.empty()) {
                    while(lower.back() == '0' && !lower.empty()) {
                        c++;
                        lower.pop_back();
                    }
                    if (!lower.empty()) {
                        lower.pop_back();
                        c++;
                    }   
                    for (int i = 0; i < c; i++) {
                        lower.push_back('0');
                    }
                }
            }

            else if (int(x)-65 < 26) { //if is upper
                upper.push_back(x);
                lower.push_back('0');
            }

            else { //if is lower
                upper.push_back('0');
                lower.push_back(x);
            }

            cin.get(x);
        }


        for (int i = 0; i < int(lower.size()); i++) {
            if (lower[i] != '0') cout << lower[i];
            if (upper[i] != '0') cout << upper[i];
        }
        cout << '\n';
    }
    return 0;
}