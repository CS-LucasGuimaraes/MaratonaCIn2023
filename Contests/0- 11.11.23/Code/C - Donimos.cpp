#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int x;

    vector<int> pizzas;
    for (int i = 0; i < n*2; i++) {
        cin >> x;
        pizzas.push_back(x);
    }
     
    sort(pizzas.begin(), pizzas.end());

    vector<int> people;
    for (int i = 0; i < n; i++) {
        people.push_back(pizzas[i]+pizzas.back());
        pizzas.pop_back();
    }

    sort (people.begin(), people.end());
    cout << people.back() - people[0];
    

    return 0;
}