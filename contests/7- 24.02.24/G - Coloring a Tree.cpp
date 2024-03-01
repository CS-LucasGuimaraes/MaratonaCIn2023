#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> target(n+1, 0);
    vector<vector<int>> children(n+1);

    int x; 

    for (int i = 2; i <= n; i++) {
        cin >> x;

        children[x].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> target[i];
    }
    
    vector<int> color(n+1, target[1]);
    int c = 1;

    queue<int> operation_order;
    operation_order.push(1);

    while(!operation_order.empty()) {
        int front = operation_order.front(); 
        operation_order.pop();

        for (auto e: children[front]) {
            color[e] = target[e];
            if (target[e] != color[front]) c++;
            operation_order.push(e);
        }
    }

    cout << c;

    return 0;
}