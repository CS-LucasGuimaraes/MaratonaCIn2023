#include <bits/stdc++.h>

#define endl '\n'
#define int long long 

using namespace std;

int solve() {

    int n; cin >> n;

    int a;

    vector<int> array;

    for (int i = 0; i < n; i++) {
        cin >> a;

        array.push_back(a);
    }
    
    int c = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            
            if (array[i] == array[j]) c++;

            else {
                int greater = max(array[i], array[j]);
                int less = min(array[i], array[j]);
                
                if (greater % less == 0)
                    if ((1 << (greater-less)) == greater/less) c++;
            }


        }

    }
    
    cout << c << endl;

    return 0;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}