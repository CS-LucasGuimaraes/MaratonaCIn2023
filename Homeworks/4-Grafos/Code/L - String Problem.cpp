#include <bits/stdc++.h>

#define INF 10e5

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t; 
    
    cin >> s >> t;

    int changes; cin >> changes;
    
    char a, b;
    int weight;

    vector<vector<pair<int,int>>> adj(97+26);

    for (int i = 0; i < changes; i++) {
        cin >> a >> b; cin >> weight;

        adj[a].push_back({weight, b});
    }

    if (s.size() != t.size()) {
        cout << -1;
        return 0;
    }

    int len = s.size();

    string answer;
    int sum = 0; 
    int c; 

    for (int i = 0; i < len; i++) {
        a = s[i];
        b = t[i];

        if (a == b) answer.push_back(a);
        else {
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> operation_order;
            vector<vector<pair<int,int>>> total_weight(2, vector<pair<int,int>>(97+26, pair<int,int>(INF, 0)));
            for (int i = 0; i < 2; i++) {

                operation_order.push({0,a});
                while(!operation_order.empty()) {

                    int wgt = operation_order.top().first;
                    int out = operation_order.top().second;

                    operation_order.pop();

                    if (wgt > total_weight[i][out].first) continue;

                    for(auto e: adj[out]) {
                        int n_wgt = e.first;
                        int next = e.second;
                        int current_wgt = total_weight[i][out].first + n_wgt;

                        if (current_wgt < total_weight[i][next].first) {
                            total_weight[i][next].first = current_wgt;
                            total_weight[i][next].second = out;
                            operation_order.push({current_wgt, next});
                        }
                    }
                }
            }

            // 

            pair<int,int> minimum(10e5,0);

            for (auto i:total_weight[0]) {
                for (auto j:total_weight[1]) {
                    if (i.second != j.second) continue;

                    if (min(i.first, j.first) < minimum.first) {
                        if (i.first < j .first) minimum = i;
                                           else minimum = j;
                    }
                }
            }

            if (minimum.second == 0) {
                cout << -1;
                return 0;
            }

            answer = minimum.second;
            sum += minimum.first;
        }
    }
    
    cout << sum << '\n' << answer;

    return 0;
}