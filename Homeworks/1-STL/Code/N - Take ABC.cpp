#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // A B C || 65 66 67

    int c;
    int flag = 0;
    deque<char> dq;

    c = getchar();
    while(c!='\n') {
        dq.push_front(c);

        if (flag == 0) {
            if (c == 65) {
                flag = 1;
                }
            else {
                flag = 0;
            }
        }
        else if (flag == 1) {
            if (c == 66) {
                flag = 2;
            }
            else if (c != 65) {
                flag = 0;
            }
        }
        else if (flag == 2) {
            if (c == 67) {
                dq.pop_front(); dq.pop_front(); dq.pop_front();
                if (dq.empty() == false) {
                    if (dq.front() == 65) {
                        flag = 1;
                    }
                    else if (dq.front() == 66) {
                        dq.pop_front();
                        if (dq.empty() == false) {
                            if (dq.front() == 65) {
                                flag = 2;
                            }
                            else {
                                flag = 0;
                            }
                        }
                        else {
                            flag = 0;
                        }
                        dq.push_front(66);
                    }
                    else {
                        flag = 0;
                    }
                }
            }
            else if (c == 65) { 
                flag = 1;
                }
            else {
                flag = 0;
            }
        }

        c = getchar();
    }
    int size = dq.size();
    for (int i = 0; i < size; i++) {
        cout << dq.back();
        dq.pop_back();
    }
    
    return 0;
}