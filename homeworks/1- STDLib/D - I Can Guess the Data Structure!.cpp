#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len, cmd, x;
    int canBeStack, canBeQueue, canBePrior;

    while (cin >> len) {
        int flag = 0;
        stack<int> stack;
        queue<int> queue;
        priority_queue<int> prior; 

        canBeStack = 1;
        canBeQueue = 1;
        canBePrior = 1;

        for (int i = 0; i < len; i++) {
            cin >> cmd;
            cin >> x;


            if (cmd == 1 && flag == 0) {
                stack.push(x);
                queue.push(x);
                prior.push(x);
            }

            if (cmd == 2 && flag == 0) {
                if (stack.empty() == true) {
                    cout << "impossible" << '\n';
                    flag = 1;
                }
                else {
                    if (stack.top() != x) canBeStack = 0;
                    if (queue.front() != x) canBeQueue = 0;
                    if (prior.top() != x) canBePrior = 0;
                    stack.pop();
                    queue.pop();
                    prior.pop();
                }
            }
        }
        if (flag == 0) {
            if (canBeStack + canBeQueue + canBePrior > 1) cout << "not sure" << '\n';
            else if (canBeStack + canBeQueue + canBePrior == 0) cout << "impossible" << '\n';
            else if (canBeStack == 1 && canBeQueue == 0 && canBePrior == 0) cout << "stack" << '\n';
            else if (canBeStack == 0 && canBeQueue == 1 && canBePrior == 0) cout << "queue" << '\n';
            else if (canBeStack == 0 && canBeQueue == 0 && canBePrior == 1) cout << "priority queue" << '\n';
        }
    }

    return 0;
}