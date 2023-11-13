#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int len1, len2, element;
    int sum = 0;
    int flag = 0; 
    // vector<int> vector;

    cin >> len1;
    for (int i = 0; i < len1; i++) {
        
        cin >> len2;
        for (int c = 0; c < len2; c++) {
            
            cin >> element;
            if (flag == 0){
                    
                if (element <= 2048){
                    sum += element;
                }
                if (sum >= 2048) {
                    flag = 1;
                    cout << "YES"<< "\n";
                }
            }
        }
        if (flag == 0) {
            cout << "NO" << "\n";
        }
        flag = 0;
        sum = 0;
    }
    
    return 0;
}