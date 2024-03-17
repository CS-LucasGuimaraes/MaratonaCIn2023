#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<set<string>> dicts;
    vector<pair<string, string>> input;

    int n; cin >> n;
    int flag = -1;
    string a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        for (int j = 0; j < dicts.size(); j++) {
            auto dict = dicts[j];

            if ( (dict.find(a)) != dict.end() || (dict.find(b)) != dict.end() ) {
                if (flag == -1) {
                    dicts[j].insert(a); dicts[j].insert(b);
                    flag = j;
                }
                else {
                    set_union(dicts[flag].begin(), dicts[flag].end(), dicts[j].begin(), dicts[j].end(), inserter(dicts[flag], dicts[flag].begin()));
                    dicts.erase(dicts.begin()+j);
                    j--;
                }
            }   
        }

        if (flag == -1) {
            dicts.push_back({a,b});
        } flag = -1;

    }

    cin >> n;

    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (auto e: dicts) {
            if (e.find(s) != e.end()) {
                if (e.size()%2==0) {
                    cout << 'S' << endl;
                }
                else {
                    cout << 'N' << endl;
                }
                break;
            }
        }
    }
    
    

    return 0;
}