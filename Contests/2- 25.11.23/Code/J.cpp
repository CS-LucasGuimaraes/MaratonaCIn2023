#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len;

    cin >> len;

    for (int i = 0; i < len; i++) {

        vector<int> brute = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,23,25,26,28,29,33,36,39,40,44,45,46,47,48,49,50,55,56,58,59,66,69,70,77,78,79,80,88,89,99,100,110,111,112,113,114,115,116,117,118,119,120,122,123,125,126,128,129,133,136,139,140,144,145,146,147,148,149,150,155,156,158,159,166,169,170,177,178,179,180,188,189,199,200};

        int left = 0;
        int right = 95;
        int mid;

        int element;

        cin >> element;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (brute[mid] < element) {
                left = mid + 1;
            }
            else if (brute[mid] > element) {
                right = mid - 1;
            }
            else {
                break;
            }
        }

        if (abs(brute[mid]-element) > abs(brute[mid-1]-element)) {
            cout << brute[mid-1] << endl;
        }

        else if (abs(brute[mid]-element)<abs(brute[mid+1]-element)) {
            cout << brute[mid] << endl;
        }
        else {
            cout << brute[mid+1] << endl;
        }
    }

    return 0;
}