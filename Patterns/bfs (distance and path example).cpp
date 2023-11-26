#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int nodes, conections;
    int x, y;

    cin >> nodes; cin >> conections;

    vector<int> network[nodes+1];

    for (int i = 0; i < conections; i++) {
        cin >> x;
        cin >> y;
        network[x].push_back(y);
        network[y].push_back(x);
    }

    queue<int> operation_order;
    vector<bool> visited;
    vector<int> distance(nodes+1);
    vector<int> distanceprev(nodes+1);
    vector<int> route[nodes+1];

    visited.assign(nodes+1, false);

    operation_order.push(1);
    while (!operation_order.empty()) {
        int i = operation_order.front();
        operation_order.pop();
        visited[i] = true;

        distance[i] = distanceprev[i]+1;

        for (auto e:network[i]) {
            if (!visited[e]) {
                operation_order.push(e);
                distanceprev[e] = distance[i];
                route[e] = route[i];
                route[e].push_back(i);
            }
        }
    }

    cout << distance[nodes] << '\n';
    for (auto e:route[nodes]) {
        cout << e << " ";
    }
    cout << nodes;

    return 0;
}