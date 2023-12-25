#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int lenght, height;
    vector<int> down, up;
    int x;

    cin >> lenght;
    cin >> height;

    for (int i = 0; i < lenght/2; i++) {
        cin >> x;
        down.push_back(x);
        cin >> x;
        up.push_back(x);
    }    

    return 0;
}