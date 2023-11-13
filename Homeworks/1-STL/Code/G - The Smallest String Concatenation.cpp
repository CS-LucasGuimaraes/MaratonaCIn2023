#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string TotalStr, PartialStr;

    int len;

    cin >> len;

    cin >> TotalStr;

    for (int i = 0; i < len-1; i++) {
        cin >> PartialStr;
        // if (lexicographical_compare(PartialStr.begin(), PartialStr.end(), TotalStr.begin(), TotalStr.end()) and PartialStr.size() <= TotalStr.size()) {
        //     PartialStr += TotalStr;
        //     swap(PartialStr, TotalStr);
        // }
        // else {
            if (lexicographical_compare((PartialStr + TotalStr).begin(), (PartialStr + TotalStr).end(), (TotalStr + PartialStr).begin(), (TotalStr + PartialStr).end())) {
                PartialStr += TotalStr;
                swap(PartialStr, TotalStr);
            }
            else {
                TotalStr += PartialStr;
            }
        // }
    }
    
    cout << TotalStr;

    return 0;
}
/*
Wrong Aswer on case 4
*/ 