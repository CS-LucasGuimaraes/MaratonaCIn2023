#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int people, friendship;
    int x, y;

    cin >> people; cin >> friendship;

    vector<vector<int>> adj(people+1);

    for (int i = 0; i < friendship; i++) {
        cin >> x; cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> operation_order;
    vector<bool> visited(people+1, false);
    vector<int> team(people+1, 0);

    for (int j = 1; j < people+1; j++)
    {
        if (!visited[j]) {
            operation_order.push(j);
            visited[j] = true;
            team[j] = 1;
        // cout << "AQUI!" << endl;
            while (!operation_order.empty()) {
                int i = operation_order.front();
                operation_order.pop();

                for (auto e:adj[i]) {
                    if (!visited[e]) {
                        if (team[i] == 1) team[e] = 2;
                        else team[e] = 1;
                        operation_order.push(e);
                        visited[e] = true;
                    }
                    if (visited[e] && team[i] == team[e]) {
                        cout << "IMPOSSIBLE";
                        return 0;
                    }
                }
            }
        }
    }


    for (int i = 1; i < people+1; i++) {
        cout << team[i] << " ";
    }
    return 0;
}