#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int quarrel; cin >> quarrel;

    vector<int> skills;
    vector<vector<int>> quarreled(n);

    int s;
    for (int i = 0; i < n; i++) {
        cin >> s;

        skills.push_back(s);
    }

    int a, b;
    for (int i = 0; i < quarrel; i++) {
        cin >> a >> b;
        a--;b--;

        quarreled[max(a,b)].push_back(min(a,b));
    }

    vector<int> answ(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (skills[i] > skills[j]) answ[i]++;
            else if (skills[i] != skills[j]) answ[j]++;
        }

        for (auto e:quarreled[i]) {
            if (skills[i] > skills[e]) answ[i]--;
            else if (skills[i] != skills[e]) answ[e]--;
        }
    }
    
    for (auto e:answ) cout << e << ' '; 

    return 0;
}