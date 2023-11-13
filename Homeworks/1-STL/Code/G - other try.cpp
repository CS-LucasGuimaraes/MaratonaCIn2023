#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string TotalStr, PartialStr;

    int len;

    cin >> TotalStr;

    for (int i = 0; i < len-1; i++) {
        cin >> PartialStr;
        if (lexicographical_compare(PartialStr.begin(), PartialStr.end(), TotalStr.begin(), TotalStr.end())){
            // is less
        }
        else {
            TotalStr += PartialStr;
        }
    }
    

    return 0;
}