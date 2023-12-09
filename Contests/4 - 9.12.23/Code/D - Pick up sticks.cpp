#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1) {
        int sticks, relations;

        cin >> sticks >> relations;

        if (sticks == 0 && relations == 0) break;

        vector<vector<int>> adj(sticks+1);
        vector<int> inDegree(sticks+1, 0);

        int a, b;

        for (int i = 0; i < relations; i++) {
            cin >> a >> b;

            adj[a].push_back(b);
            inDegree[b]++;
        }

        queue<int> operation_order;
        vector<bool> visited(sticks+1, false);
        queue<int> answer;

        for (int i = 1; i < sticks+1; i++) {
            if (inDegree[i] == 0) {
                operation_order.push(i);
            }
        }

        while(!operation_order.empty()) {
            int i = operation_order.front();
            operation_order.pop();
            answer.push(i);

            for (auto e: adj[i]) {
                if (--inDegree[e] == 0) {
                    operation_order.push(e);
                }
            }
        }

        int ans_size = answer.size();
        if (ans_size == sticks) {
            while (!answer.empty()) {
                cout << answer.front() << '\n';
                answer.pop();
            }
        }
        else cout << "IMPOSSIBLE" << '\n';

    }

    return 0;
}