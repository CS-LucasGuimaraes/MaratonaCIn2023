#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {

    int k; cin >> k;

    vector<int> array;

    int c;

    for (int i = 0; i < k; i++) {
        cin >> c;

        c = c%k; if (c < 0) c += k; 

        array.push_back(c);
    }

    for (int i = 1; i < k; i++) {
        if (array[i] == array[i-1]-1) return false;  
    }

    if (array[0] == array[k-1]-1) return false;

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

// n k n-2
// 1 3 2 3 1    