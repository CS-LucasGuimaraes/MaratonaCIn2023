#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int len;
    int x;
    int xa;
    int xb;
    int xc;
    int xd;
    vector<int> a(len);
    vector<int> b;
    vector<int> c;
    vector<int> d;
    vector<int> sumAB;
    vector<int> sumCD;

    int count = 0;

    cin >> len;

    for (int i = 0; i < len; i++) {
        cin >> ai;
        // a.push_back(xa);
        // cout << a.back() << endl;

        cin >> xb;
        b.push_back(xb);
        // cout << a.back() << endl;
        // cout << b.back() << endl;

        cin >> xc;
        c.push_back(xc);
        
        cin >> xd;
        d.push_back(xd);
    }
    
    for (auto element_a:a) {
        for (auto element_b:b) {
            sumAB.push_back(element_a+element_b);
        }
    }

    for (auto element_c:c) {
        for (auto element_d:d) {
            sumCD.push_back(element_c+element_d);
        }
    }

    for (auto element:sumAB) {
        x = sumCD.back();
        sumCD.pop_back();
        
        if (element == -x) {
            count++;
        }
    }

    cout << count;

    return 0;
}