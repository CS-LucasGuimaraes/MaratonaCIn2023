#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tree_size, max_cats;
    int cats_in_a_row = 0;

    cin >> tree_size;
    cin >> max_cats;

    vector<bool> vertex_with_cat;
    vertex_with_cat.push_back(0);
    int x, y;

    vector<int> tree_struct[tree_size+1];

    for (int i = 0; i < tree_size; i++) {
        cin >> x;
        vertex_with_cat.push_back(x);
    }

    for (int i = 1; i < tree_size; i++) {
        cin >> x;
        cin >> y;
        tree_struct[x].push_back(y);
        tree_struct[y].push_back(x); // bi-direcional (erro no caso 8)
    }

    // int leaf_start = x+1;

    stack<int> operation_order;
    vector<bool> visited;
    map<int,int> catsprev;
    vector<int> possible_restaurants;

    visited.assign(tree_size+1, false);
    
    operation_order.push(1);
    while (!operation_order.empty()) {
        int i = operation_order.top();
        operation_order.pop();
        visited[i] = true;

        cats_in_a_row = catsprev[i];

        if (vertex_with_cat[i]) cats_in_a_row++;
        else cats_in_a_row = 0;

        if (cats_in_a_row <= max_cats) {
            for(auto e:tree_struct[i]) {
                if(!visited[e]) {
                    operation_order.push(e);
                    catsprev[e] = cats_in_a_row;
                }
            }
        }

        if (tree_struct[i].size() == 1 && cats_in_a_row <= max_cats && i != 1) {
            possible_restaurants.push_back(i);
        }
    }

    cout << possible_restaurants.size();

    return 0;
}