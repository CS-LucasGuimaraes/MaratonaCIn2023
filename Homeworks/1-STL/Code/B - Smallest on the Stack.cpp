#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len;
    stack<int> gifts;
    stack<int> min_stack;
    string action;

    cin >> len;

    for (int i = 0; i < len; i++) {
        
        cin >> action;
        
        if(action == "PUSH"){
            int x;
            cin >> x;
            gifts.push(x);

            if (min_stack.empty() == true) {
                min_stack.push(x);
            }
            else if (min_stack.top() >= x) {
                min_stack.push(x);
            }
        }

        if(action == "POP") {
            if (gifts.empty() == true) cout << "EMPTY\n";
            else if (gifts.top() == min_stack.top()){
                min_stack.pop();
                gifts.pop();
            }
            else gifts.pop();
        }
    
        if(action == "MIN") {
            if (gifts.empty() == true) cout << "EMPTY\n";
            else{
                cout << min_stack.top() << "\n";
            }
        }
    }
    // if (gifts.empty() == false) cout << gifts.top();
    
    return 0;
}