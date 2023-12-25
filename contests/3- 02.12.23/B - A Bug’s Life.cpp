#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(2e3+2);
vector<bool> colored(2e3, false);
vector<bool> color(2e3+2, false);


bool bipart(int e) {
    colored[e] = true;
    for(auto u:adj[e]) {
        if (!colored[u]) {
            color[u] = !color[e];
            colored[u] = true;
            if (!bipart(u)) return false;
        }
        else if (color[e] == color[u]) return false;
    }
    return true;
}

int controller() {
    int bugs, interactions;
    int x, y;

    cin >> bugs; cin >> interactions;


    for (int i = 0; i < interactions; i++) {
        cin >> x; cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    for (int i = 1; i < bugs+1; i++) {
        if (!colored[i]) {
            if (!bipart(i)) {
                cout << "Suspicious bugs found!" << '\n';
                return 0;
            }   
        }
    }

    cout << "No suspicious bugs found!" << '\n';
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases;

    cin >> test_cases;

    for (int tc = 1; tc < test_cases+1; tc++) {
        fill(colored.begin(), colored.end(), false);
        fill(color.begin(), color.end(), false);
        fill(adj.begin(), adj.end(), vector<int>(false));

        cout << "Scenario #" << tc << ":" << '\n';
        controller();
    }

    return 0;
}       