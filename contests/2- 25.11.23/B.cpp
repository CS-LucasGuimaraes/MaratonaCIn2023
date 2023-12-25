#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_cases;
    int x, y, h;
    int x_note, y_note, x_proj, y_proj;

    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        cin >> x; cin >> y; cin >> h;
        cin >> x_note; cin >> y_note;
        cin >> x_proj; cin >> y_proj;


        int left = x_note + x_proj;
        int right =  x - x_note + x - x_proj;
        int down = y_note + y_proj;
        int up = y - y_note + y - y_proj;

        int minX = min(left, right);
        int minY = min(down,up);
        // int minT = min(minX, minY);

        double path;

        if (minX < minY) {
            path = minX + abs(y_note - y_proj) + h;
        }
        else if (minY < minX) {
            path = minY + abs(x_note - x_proj) + h;
        }
        
        cout << path << '\n';
    }
    
    return 0;
}