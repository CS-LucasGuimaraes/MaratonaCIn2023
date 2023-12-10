#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string TotalStr, PartialStr;
    vector<string> vec;

    int len;

    cin >> len;

    for (int i = 0; i < len; i++) {
        cin >> PartialStr;
        vec.push_back(PartialStr);
    }
    sort(vec.begin(), vec.end());


    for (auto PartialStr:vec) {
        if (lexicographical_compare((PartialStr + TotalStr).begin(), (PartialStr + TotalStr).end(), (TotalStr + PartialStr).begin(), (TotalStr + PartialStr).end())) {
            PartialStr += TotalStr;
            swap(PartialStr, TotalStr);
        }
        else {
            TotalStr += PartialStr;
        }
    }
       
    cout << TotalStr;

    return 0;
}
/*
Wrong Aswer on case 4
*/ 