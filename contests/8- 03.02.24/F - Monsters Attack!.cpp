#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using pii = pair<int,int>;

int solve() {

    int monster, bullets; cin >> monster >> bullets;

    priority_queue<pii, vector<pii>, greater<pii>> monsters;
    vector<int> health(monster);

    int pos;

    for (int i = 0; i < monster; i++) {
        cin >> health[i];
    }

    for (int i = 0; i < monster; i++) {
        cin >> pos;

        monsters.push({abs(pos), health[i]});
    }
    
    int dist, life;
    int traveled = 0;

    while (!monsters.empty()){
        dist = monsters.top().first;
        life = monsters.top().second;
        monsters.pop();

        if (life>0) {
            if (traveled+ceil(life/bullets) > dist) {
                cout << "NO" << endl;
                return 0;
            }
        }
        
        while (life > 0) {
            life -= bullets;
            traveled += 1;
        }

        if (life < 0 && !monsters.empty()) {
            pii next = monsters.top();
            monsters.pop();
            next = {next.first, next.second+life};
            monsters.push(next);

            if (next.second > 0) {
                if (traveled+ceil(next.second/bullets) > next.first) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            else { // if next.second <= 0
                if (traveled > next.first) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }

    }

    cout << "YES" << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}