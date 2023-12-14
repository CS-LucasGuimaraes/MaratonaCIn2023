#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> queue1, queue2;

struct choice {
    int q1, q2, q3, max;
};

vector<choice> bestchoice(1e5, {-1, -1, -1, -1});

choice makeChoice(int n) {
    if (bestchoice[n].max != -1) return bestchoice[n];

    if (n == 0) {
        return bestchoice[n] = {queue1[n], queue2[n], 0, max(queue1[n], queue2[n])};
    }

    int a = max(makeChoice(n-1).q2+queue1[n], makeChoice(n-1).q3+queue1[n]);
    int b = max(makeChoice(n-1).q1+queue2[n], makeChoice(n-1).q3+queue2[n]);
    int c = makeChoice(n-1).max;

    return bestchoice[n] = {a, b, c, max(a, max(b, c))};
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int queue_size; cin >> queue_size;

    int x;

    for (int i = 0; i < queue_size; i++) {
        cin >> x;
        queue1.push_back(x);
    }

    for (int i = 0; i < queue_size; i++) {
        cin >> x;
        queue2.push_back(x);
    }

    cout << makeChoice(queue_size-1).max;

    return 0;
}