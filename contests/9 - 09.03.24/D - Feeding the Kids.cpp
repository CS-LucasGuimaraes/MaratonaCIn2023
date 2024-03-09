#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
#define int long long //change main to int32_t

int students, pizzas;
vector<int> arr(10e5+1);

bool solve(int k) {

    int sum = 0;
    int groups = 1;

    for (int i = 0; i < students; i++) {
        if (sum + arr[i] <= k) sum += arr[i];
        else {
            sum = arr[i];
            groups += 1;
            if (groups > pizzas) {
                return false;
            }
        }
    }
    return true;
    

    return 0;
}

int binarySearch(int l, int r)
{
    int answ;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // If NOT SOLVE, ignore left half
        if (!solve(m))
            l = m + 1;
 
        // If SOLVE, ignore right half
        else {
            answ = m;
            r = m - 1;
        }
    }
 
    return answ;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> students >> pizzas;

    int maxint = 0;
    int sum = 0;

    for (int i = 0; i < students; i++) {
        cin >> arr[i];

        sum += arr[i];

        if (arr[i] > maxint) maxint = arr[i];
    }

    
    cout << binarySearch(maxint, sum);
    

    return 0;
}