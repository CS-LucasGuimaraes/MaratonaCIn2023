#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cities, roads;
    int x, y;

    cin >> cities; cin >> roads;

    vector<vector<int>> adj(cities+1);

    for (int i = 0; i < roads; i++) {
        cin >> x; cin >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    queue<int> operation_order;
    vector<bool> visited;
    vector<int> first_element;

    visited.assign(cities+1, false);

    for (int i = 1; i < cities+1; i++) {
        if (!visited[i]) {
            first_element.push_back(i);

            operation_order.push(i);
            visited[i] = true;
            while (!operation_order.empty()) {
                int i = operation_order.front();
                operation_order.pop();

                for (auto e:adj[i]) {
                    if (!visited[e]) {
                        operation_order.push(e);
                        visited[e] = true;
                    }
                }
            }
        }
    }

    int size = first_element.size();

    cout << size-1 << '\n';

    for (int i = 0; i < size-1; i++) {
        cout << first_element[i] << " " << first_element[i+1] << '\n';
    }
    

    return 0;
}