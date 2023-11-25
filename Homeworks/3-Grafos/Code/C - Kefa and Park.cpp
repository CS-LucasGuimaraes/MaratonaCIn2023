#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tree_size, max_cats;

    cin >> tree_size;
    cin >> max_cats;

    vector<bool> vertex_with_cat;
    int x, y;

    vector<vector<int>> tree_struct;

    for (int i = 0; i < tree_size; i++) {
        cin >> x;
        vertex_with_cat.push_back(x);
    }

    tree_struct.push_back({0});
    for (int i = 1; i < tree_size; i++) {
        cin >> x;
        cin >> y;
        tree_struct[x].push_back(y);
    }

    int leaf_start = x+1;

    // stack<int> operation_order;
    // vector<int> visited;

    // for (auto conection:tree_struct[1]){
    //     operation_order.push(conection);
    //     visited.push_back(1);
    // }

    
    // IMPLEMENTAR DFS
    
    

    return 0;
}