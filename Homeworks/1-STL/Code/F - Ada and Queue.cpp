#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    deque<int> toDo, reverse_toDo;
    int len, x;
    string action;

    cin >> len;

    for (int i = 0; i < len; i++)
    {
        cin >> action;
        if (action == "push_back") {
            cin >> x;
            toDo.push_back(x);
        }

        else if (action == "toFront") {
            cin >> x;
            toDo.push_front(x);
        }

        else if (action == "back") { 
            if (toDo.empty() == false) {
                cout << toDo.back() << "\n";
                toDo.pop_back();
            }
            else cout << "No job for Ada?" << "\n";
        }

        else if (action == "front") { 
            if (toDo.empty() == false) {
                cout << toDo.front() << "\n";
                toDo.pop_front();
            }
            else cout << "No job for Ada?" << "\n";
        }
        
        // 2x linear
        else if (action == "reverse") {
            // if (toDo.empty() == false) {
            //     while (toDo.empty() == false) {
            //         reverse_toDo.push_front(toDo.front());
            //         toDo.pop_front();
            //     }
                
            //     while (reverse_toDo.empty() == false) {
            //         toDo.push_front(reverse_toDo.back());
            //         reverse_toDo.pop_back();
            //     }
            // }
            reverse(toDo.begin(), toDo.end());
        }
    }
    
    return 0;
}