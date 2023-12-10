#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll computers, conections;
    ll x, y;

    cin >> computers; cin >> conections;

    vector<ll> network[computers+1];

    for (ll i = 0; i < conections; i++) {
        cin >> x;
        cin >> y;
        network[x].push_back(y);
        network[y].push_back(x);
    }

    queue<ll> operation_order;
    vector<bool> visited;
    // vector<ll> route[computers+1];
    vector<ll> father(computers+1);

    visited.assign(computers+1, false);
    father.assign(computers+1, 0);

    operation_order.push(1);
    visited[1] = true;
    while (!operation_order.empty()) {
        ll i = operation_order.front();
        operation_order.pop();
        // visited[i] = true;


        for (auto e:network[i]) {
            if (!visited[e]) {
                operation_order.push(e);
                visited[e] = true;
                // route[e] = route[i];
                // route[e].push_back(i);
                father[e] = i;
            }
        }
    }


    if (father[computers] == 0) {
        cout << "IMPOSSIBLE";
    }
    else {
        deque<ll> route;
        int i = computers;
        while (i != 1) {
            route.push_front(i);
            i = father[i];
        }
        route.push_front(1);
        
        cout << route.size() << '\n';
        for (auto e:route) {
            cout << e << " ";
        }
    }

    return 0;
}