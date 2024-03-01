#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, queries; cin >> n >> queries;

    string s; cin >> s;

    vector<int> prefix;
    prefix.push_back(0);
    prefix.push_back(0);
    int c = 0;
    
    for (int j = 1; j < n; j++) {
        if (s[j] == s[j-1]) c++;

        prefix.push_back(c);
    }

    int a, b;
    
    for (int i = 0; i < queries; i++) {
        cin >> a >> b;
        
        cout << prefix[b]-prefix[a] << endl;
   
    }
    

    return 0;
}