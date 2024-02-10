#include <bits/stdc++.h>

#define endl '\n'
const int INF = INT_MAX;

using namespace std;
using ll = long long;
using pii = pair<int,int>;

/*
A = 100 = 2^2 = 4
B = 010 = 2^1 = 2
C = 001 = 2^0 = 1

AB = 110 = 4+2 = 6
AC = 101 = 4+1 = 5
BC = 011 = 2+1 = 1

ABC = 111 = 7
*/

int juice_number; 

vector<ll> total_cost(8,-1);
vector<pii> juices;


ll solveDp(int mask) {
    if (mask == 7) return total_cost[mask] = 0;     // Base case
    if (total_cost[mask] != -1) return total_cost[mask];    // Memoization
    
    total_cost[mask] = INF; 

    for (int i = 0; i < juice_number; i++) {
        int new_cost = juices[i].first;
        int new_mask = juices[i].second;

        if (mask | new_mask != mask) { // If the juice added any new vitamin    // Avoids cicles
            total_cost[mask] = min(total_cost[mask], new_cost + solveDp(mask | new_mask));
        }
    }
    
    return total_cost[mask];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> juice_number;

    int cost; 
    string vitamins;
    int mask;

    for (int i = 0; i < juice_number; i++) {
        cin >> cost >> vitamins;

        mask = 0;

        for (auto e: vitamins) {
                 if (e == 'A') mask += 4;
            else if (e == 'B') mask += 2;
            else if (e == 'C') mask += 1;
        }

        juices.push_back({cost, mask});

    }
    
    int answ = solveDp(0);
    if (answ == INF) answ = -1;
    cout << answ;

    return 0;
}