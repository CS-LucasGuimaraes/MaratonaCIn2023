#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int start, end;

    int tv1 = -1;
    int tv2 = -1;

    vector<pii> shows;

    for (int i = 0; i < n; i++) {
        cin >> start >> end;

        shows.push_back({start, end});
    }

    sort(shows.begin(), shows.end());

    for (auto e:shows){
        start = e.first;
        end = e.second; 

        if (tv1 < start) {
            tv1 = end;
        }

        else if (tv2 < start) {
            tv2 = end;
        }

        else {
            cout << "NO";
            return 0;
        }

    }

    cout << "YES";

    return 0;
}