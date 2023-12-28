#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void solve(){
    int battlefields, greenSoldiers, blueSoldiers;

    cin >> battlefields >> greenSoldiers >> blueSoldiers;

    priority_queue<int> greenArmy;
    priority_queue<int> blueArmy;

    int x;

    for (int i = 0; i < greenSoldiers; i++) {
        cin >> x;

        greenArmy.push(x);
    }

    for (int i = 0; i < blueSoldiers; i++) {
        cin >> x;

        blueArmy.push(x);
    }

    ///


    while(!greenArmy.empty() && !blueArmy.empty()){
        vector<int> actual_green;
        vector<int> actual_blue;

        int k = 0;

        for (int i = 0; i < battlefields; i++) {
            if (!greenArmy.empty() && !blueArmy.empty()){
                actual_green.push_back(greenArmy.top());
                actual_blue.push_back(blueArmy.top());

                greenArmy.pop(); blueArmy.pop();
                k++;
            }
        }

        for (int i = 0; i < k; i++) {
            if (actual_green[i] > actual_blue[i]) greenArmy.push(actual_green[i]-actual_blue[i]);
            else if (actual_green[i] < actual_blue[i]) blueArmy.push(actual_blue[i]-actual_green[i]);
        }
        
    }

    if (greenArmy.empty() && blueArmy.empty()) cout << "green and blue died" << endl;
    else if (!greenArmy.empty()) {
        cout << "green wins" << endl;
        while(!greenArmy.empty()) {
            cout << greenArmy.top() << endl;
            greenArmy.pop();
        }
    }
    else if (!blueArmy.empty()) {
        cout << "blue wins" << endl; 
        while(!blueArmy.empty()) {
            cout << blueArmy.top() << endl;
           blueArmy.pop();
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
        if (tc) cout << '\n';
    }

    return 0;
}