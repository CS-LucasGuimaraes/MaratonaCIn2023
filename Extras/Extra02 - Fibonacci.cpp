#include <bits/stdc++.h>

using namespace std;

vector<long long> store_fib(1000, -1);

long long fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (store_fib[n] != -1) return store_fib[n];

    return store_fib[n] = fib(n-1) + fib(n-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    cout << fib(n);

    return 0;
}