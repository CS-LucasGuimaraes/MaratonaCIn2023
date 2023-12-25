#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases; cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        int athletes; cin >> athletes;

        vector<int> list;

        int x;
        for (int i = 0; i < athletes; i++) {
            cin >> x;

            list.push_back(x);
        }
        
        sort(list.begin(), list.end());

        int len = list.size();

        priority_queue<int, vector<int>, greater<int>> sum;

        for (int i = 0; i < len-1; i++) {
            sum.push(abs(list[i] - list[i+1]));
        }
        
        cout << sum.top() << '\n';

    }
     

    return 0;
}