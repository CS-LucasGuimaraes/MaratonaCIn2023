#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n, k, x;
vector<int> array_a;
vector<int> array_b;
vector<int> array_c;
vector<int> array_d;

int solve(int i, int rating) {
    
    if (i == n) {
        return rating;
    }

    int a, b, c, d; a = array_a[i]; b = array_b[i]; c = array_c[i]; d = array_d[i];     

    if (rating < x-k) {
        // NORMAL GAME
        if (c) return solve(i+1, rating+a);
        else return solve(i+1, rating-b);
    }

    else if (rating > x+k) {
        // BC GAME
        if (d) return solve(i+1, rating+a);
        else return solve(i+1, rating-b);
    }

    else {
        if (c == d) {
            if (c) return solve(i+1, rating+a);
            else return solve(i+1, rating-b);
        }

    }

    return max(solve(i+1, rating+a), solve(i+1, rating-b));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> x;

    int rating;

    rating = x;

    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;

        array_a.push_back(a);
        array_b.push_back(b);
        array_c.push_back(c);
        array_d.push_back(d);
    }

    rating = solve(0, rating);

    cout << rating;

    return 0;
}