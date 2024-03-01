#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int health = 0;

    priority_queue<int, vector<int>, greater<int>> minheap;

    int x;
    int c = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        c++;

        health+=x;
        minheap.push(x);

        if (health < 0) {
            health -= minheap.top();
            minheap.pop();
            c--;
        }

    }
    
    cout << c;

    return 0;
}