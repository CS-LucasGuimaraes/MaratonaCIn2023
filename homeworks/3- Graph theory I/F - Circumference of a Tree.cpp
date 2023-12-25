#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int nodes;
    int x,y;

    cin >> nodes;

    vector<int> adjacency[nodes+1];

    for (int i = 1; i < nodes; i++) {
        cin >> x;
        cin >> y;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }


    int max_dist = 0;
    int max_dist_index = 1;
    for (int rep = 0; rep < 2; rep++) {
        queue<int> operation_order;
        vector<bool> visited;
        vector<int> distance(nodes+1);

        visited.assign(nodes+1, false);

        operation_order.push(max_dist_index);
        distance[max_dist_index] = 0;
        while(!operation_order.empty()) {
            int i = operation_order.front();
            operation_order.pop();

            for(auto e:adjacency[i]) {
                if (!visited[e]) {
                    operation_order.push(e);
                    distance[e] = distance[i]+1;
                    if (distance[e] > max_dist) {
                        max_dist = distance[e];
                        max_dist_index = e;
                    }
                    visited[e] = true;
                }
            }
        }
    }

    cout << max_dist*3 << '\n';

    return 0;
}