#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int machines, products, machine_time;
    vector<int> machinesList;

    cin >> machines;
    cin >> products;

    for (int i = 0; i < products; i++) {
        cin >> machine_time;
        machinesList.push_back(machine_time);
    }
    
    sort(machinesList.begin(), machinesList.end());

    

    return 0;
}