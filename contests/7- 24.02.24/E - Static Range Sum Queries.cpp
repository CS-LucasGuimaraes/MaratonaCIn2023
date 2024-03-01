#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int values, queries; cin >> values >> queries;

    int x;

    vector<int> array;

    for (int i = 0; i < values; i++) {
        cin >> x;

        array.push_back(x);
    }

    vector<int> prefix;

    prefix.push_back(0);

    for (auto e: array) {
        prefix.push_back(prefix.back()+e);
    }

    int a, b;

    for (int i = 0; i < queries; i++) {
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << endl;
    }

    return 0;
}