#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

bool lex_sort(string a, string b) {
    return a + b < b + a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    string s;

    vector<string> ss;

    for (int i = 0; i < n; i++) {
        cin >> s;

        ss.push_back(s);
    }

    sort(ss.begin(), ss.end(), lex_sort);

    for (auto e: ss) {
        cout << e;
    }
    

    return 0;
}