#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; n /= 2;

    int x, y;

    vector<pair<int,int>> bf;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        if (x > y ) bf.push_back({y, x});
        else bf.push_back({x, y});
    }

    sort(bf.begin(), bf.end());

    vector<pair<int,int>> bf2;
    vector<int> answer;
    vector<bool> visited(n, false);

    int size = bf.size();

    x = bf[0].first;
    y = bf[0].second;
    answer.push_back(x); answer.push_back(y);
    visited[0] = true;

    for (int i = 1; i < size; i++) {
        x = bf[i].first;
        y = bf[i].second;
        if (x > answer.back()) {
            answer.push_back(x); answer.push_back(y);
            visited[i] = true;
        }
    }
    

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            x = bf[i].first;
            y = bf[i].second;

            bf2.push_back({y, x});
        }
    }

    sort(bf2.rbegin(), bf2.rend());

    size = bf2.size();

    if (size > 0) {
        x = bf2[0].first;
        y = bf2[0].second;
        answer.push_back(x); answer.push_back(y);
    }

    for (int i = 1; i < size; i++) {
        x = bf2[i].first;
        y = bf2[i].second;
        if (x < answer.back()) {
            answer.push_back(x); answer.push_back(y);
        }
    }    
    
    if (answer.size() == n*2) {
        for (auto e: answer) cout << e << ' ';
    }
    else cout << -1;
     

    return 0;
}