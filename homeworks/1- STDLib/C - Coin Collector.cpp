    #include <bits/stdc++.h>

    #define endl '\n'

    using namespace std;

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);

        int tc; cin >> tc; while (tc--) {
            int n; cin >> n;

            vector<int> coins;

            int x;

            for (int i = 0; i < n; i++) {
                cin >> x;

                coins.push_back(x);
            }
            
            int sum = 0, c = 1; // the last always enter.

            for (int i = 0; i < n-1; i++) {
                if (sum+coins[i] < coins[i+1]) {
                    sum += coins[i];
                    c++;
                }
            }

            cout << c << endl;
            
        }

        return 0;
    }