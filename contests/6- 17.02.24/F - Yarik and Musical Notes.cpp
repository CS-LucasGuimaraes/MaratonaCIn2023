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

    vector<int> pow2;

    for (int i = 0; i < n; i++) {
        a = (1 << array[i]);
        pow2.push_back(a);
    }
    
    int c = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            
            if (array[i] == array[j]) c++;

            else {
                if (array[i] == 1 || array[j] == 1 || (array[i] %2 == 0 && array[j] %2 == 0))
                    if (array[i]*pow2[j] == array[j]*pow2[i]) c++;
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