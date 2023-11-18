#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int len;

    // cin >> len;

    // for (int i = 0; i < len; i++) {
        int fuelstop, dist, fuel;
        pair<int, int> stop;
        vector<pair<int,int>> stopList;
        bool possible = true;

        cin >> fuelstop;

        for (int j = 0; j < fuelstop; j++) {
            cin >> dist;
            cin >> fuel;

            stop.first = dist;
            stop.second = fuel;

            stopList.push_back(stop);
        }
        sort(stopList.begin(), stopList.end(), greater<pair<int, int>>());

        int actual_fuel, actual_dist;
        int stopNumber = 0;
        cin >> actual_dist;
        cin >> actual_fuel;

        for (size_t k = 0; k < stopList.size(); k++) {
            // cout << e.first << '\n';
            actual_fuel -= actual_dist-stopList[k].first;
            actual_dist -= actual_dist-stopList[k].first;

            if (actual_fuel < stopList[k+1].first) {

                if (actual_fuel >= 0) {
                    actual_fuel += stopList[k].second;
                }
                else {
                    possible = false;
                }
                cout << "STOP: " << stopList[k].first << '\n';
                stopNumber++;
            }
            cout << "FUEL: " << actual_fuel << '\n';
            stopList.pop_back();
        }

        if (possible && actual_dist <= actual_fuel) {
            cout << stopNumber;
        }
        else {
            cout << -1;
        }   

    // }
    
    return 0;
}   