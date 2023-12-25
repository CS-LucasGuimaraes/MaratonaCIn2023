#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len, len2, student;

    cin >> len;

    for (int i = 0; i < len; i++) {
        
        vector<int> v;

        cin >> len2;

        for (int j = 0; j < 3*len2; j++) {
            cin >> student;
            v.push_back(student);
        }
        sort(v.begin(), v.end());

        int sum = 0;
        for (int k = v.size()/3; k < v.size(); k+=2) {
            sum += v[k];
        }
        cout <<  sum << '\n';
        
        
    }
    

    return 0;
}