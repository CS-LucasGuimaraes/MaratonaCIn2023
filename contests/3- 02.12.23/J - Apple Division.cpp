#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll apples, x;

    cin >> apples;

    vector<ll> weight;

    for (ll i = 0; i < apples; i++){
        cin >> x;
        weight.push_back(x);
    }

    sort(weight.begin(), weight.end());

    vector<ll> group1, group2;
    ll sum1 = 0, sum2 = 0;

    while(!weight.empty()){
        group1.push_back(weight.back());
        sum1 += weight.back();
        weight.pop_back();

        while (sum1 > sum2 && !weight.empty()) {
            for (int i = 0; i < int(weight.size()); i++){
                if (weight[i] == sum1-sum2) {
                    sum2+= weight[i];
                    group2.push_back(weight[i]);
                    weight.erase(weight.begin()+i);
                    break;
                }
                if (weight[i] > sum1-sum2) {
                    sum2+= weight[i-1];
                    group2.push_back(weight[i-1]);
                    weight.erase(weight.begin()+(i-1));
                    break;
                }
                else if (i == int(weight.size()-1)) {
                    // sum2+= weight[i];
                    // group2.push_back(weight[i]);
                    sum2 += weight.back();
                    group2.push_back(weight.back());
                    // weight.erase(weight.begin()+(i));
                    weight.pop_back();
                    break;
                }
            }
        }
    }

    cout << abs(sum1-sum2);

    return 0;
}