#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(10e5);
vector<bool> visited(10e5, false);
stack<int> answer;

void topoSort(int i) {
    if (visited[i] == true) return;

    visited[i] = true;

    for (auto e: adj[i]) {
        topoSort(e);
    }
    answer.push(i);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int courses, requirements;
    int prev, act;

    cin >> courses; cin >> requirements;
    vector<bool> canBeFirst(courses+1, true);

    for (int i = 0; i < requirements; i++) {
        cin >> prev; cin >> act;
        adj[prev].push_back(act);
        canBeFirst[act] = false;
    }

    for (int i = 1; i < courses+1; i++) {
        // if (canBeFirst[i]) {
            topoSort(i);
        // }
    }
    
    while (!answer.empty()) {
        cout << answer.top() << " ";
        answer.pop();
    }
    


    return 0;
}

/// Tem que codar com khan algorithm pra pegar se for cíclico e printar que é impossível.