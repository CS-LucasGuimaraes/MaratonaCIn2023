#include <bits/stdc++.h>

using namespace std;

int code() {
    int soldiers, conditions;
    string a, b, c;
    // int x, y, d;

    cin >> soldiers; cin >> conditions;
    cin.get();


    vector<int> pos(soldiers+1);
    vector<bool> defined(soldiers+1, false);
    bool exit = false;


    vector<string> strings;
    string str;
    for (int i = 0; i < conditions; i++) {
        getline(cin, str);
        strings.push_back(str);
    }

    sort(strings.begin(), strings.end());

    for (int i = 0; i < conditions; i++) {
        // cin >> x; cin >> y; cin >> d;
        stringstream input (strings[i]);

        getline(input, a, ' ');
        getline(input, b, ' ');
        getline(input, c);

        // cout << "AQUI!" << a << " " << b << " " << c << endl; 

        int x    = stoi(a); int y = stoi(b); int d = stoi(c);

        if (exit) continue;

        if (!defined[x] && !defined[y]) {
            pos[y] = 0; 
            pos[x] = pos[y] + d;
        }
        else if (!defined[x] && defined[y]) {
            pos[x] = pos[y] + d;
        }
        else if (defined[x] && !defined[y]) {
            pos[y] = pos[x] - d;
        }
        else if (defined[x] && defined[y]) {
            if (pos[x] != pos[y] + d) {
                cout << "No" << '\n';
                exit = true;
            }
            
        }
        defined[x] = true;
        defined[y] = true;
    }
    

    if (!exit) cout << "Yes" << '\n';

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases;

    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        code();
    }
    

    return 0;
}