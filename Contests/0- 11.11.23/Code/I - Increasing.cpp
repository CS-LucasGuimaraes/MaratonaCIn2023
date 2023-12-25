    #include <bits/stdc++.h>

    #define endl '\n'

    using namespace std;

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);

        int tc; cin >> tc; while (tc--) {
            int n; cin >> n;

            int x;
            bool flag = false;

            set<int> array;

            for (int i = 0; i < n; i++) {
                cin >> x;
                if (flag) continue;
                if (array.find(x) == array.end()) {
                    array.insert(x);
                }
                else{
                    cout << "No" << endl;
                    flag = true;
                }
            }
            if (!flag) cout << "Yes" << endl;
        }

        return 0;
    }