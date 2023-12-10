#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int len;

    cin >> len;

    for (int i = 0; i < len; i++) {
        int battlefields, greenNumber, blueNumber, soldier;
        priority_queue<int> greenArmy, blueArmy;

        cin >> battlefields;
        cin >> greenNumber;
        cin >> blueNumber;

        for (int j = 0; j < greenNumber; j++) {
            cin >> soldier;
            greenArmy.push(soldier);
        }
        for (int j = 0; j < blueNumber; j++) {
            cin >> soldier;
            blueArmy.push(soldier);
        }
// !!!2 =============================================
        stack<int> greenFight, blueFight;
        while (1) {
            for (int k = 0; k > battlefields; k++) {
                if (greenFight.empty() == false && blueFight.empty() == false) {

                    greenFight.push(greenArmy.top());
                    blueFight.push(blueArmy.top());
                    greenArmy.pop();
                    blueArmy.pop();
                }
            }

    // 3 #############################################
            for (int k = 0; k > battlefields; k++) {
                if (greenFight.empty() == false && blueFight.empty() == false) {
                    if (greenFight.top() > blueFight.top()) {
                        greenArmy.push(greenFight.top() - blueFight.top());
                    }
                    if (greenFight.top() < blueFight.top()) {
                        blueArmy.push(blueFight.top() - greenFight.top());
                    }
                    if (greenFight.top() < blueFight.top()) {
                    }
                    greenFight.pop();
                    blueFight.pop();
                }
            }
    // 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++

            if (greenArmy.empty() == true || blueArmy.empty() == true) {

                if (greenArmy.empty() == true && blueArmy.empty() == true) {
                    cout << "green and blue died\n\n";
                    break;
                }
                else if (greenArmy.empty() == true) {
                    cout << "blue wins\n";
                    break;
                    while (blueArmy.empty() == false) {
                        cout << blueArmy.top() << '\n';
                        blueArmy.pop();
                    }
                    cout << '\n';
                }
                else if (blueArmy.empty() == true) {
                    cout << "green wins\n";
                    break;
                    while (greenArmy.empty() == false) {
                        cout << greenArmy.top() << '\n';
                        greenArmy.pop();
                    }
                    cout << '\n';
                }
            }
        }
    return 0;
    }
}
