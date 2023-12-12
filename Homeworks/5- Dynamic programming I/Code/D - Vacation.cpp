#include <bits/stdc++.h>

using namespace std;

struct actv{
    int a, b, c;  
};

struct choice{
    string choice;
    int value;
};

vector<choice> bestchoice(1e5, {'z', -1});
vector<actv> vacation;

choice makechoise(int x) {
    if (bestchoice[x].value != -1) return (bestchoice[x]);

    if (x == 1) {
        if (vacation[x].a == vacation[x].b && vacation[x].b == vacation[x].c) return bestchoice[x] = {"abc", vacation[x].a};
        
        else if (vacation[x].a == vacation[x].b && vacation[x].a > vacation[x].c) return bestchoice[x] = {"ab", vacation[x].a};
        
        else if (vacation[x].a > vacation[x].b && vacation[x].a > vacation[x].c) return bestchoice[x] = {"a", vacation[x].a};
        
        else if (vacation[x].a < vacation[x].b && vacation[x].b == vacation[x].c) return bestchoice[x] = {"bc", vacation[x].b};

        else if (vacation[x].a < vacation[x].b && vacation[x].b > vacation[x].c) return bestchoice[x] = {"b", vacation[x].b};

        else if (vacation[x].c > vacation[x].a && vacation[x].c > vacation[x].b) return bestchoice[x] = {"c", vacation[x].c};



        bestchoice[x] = {'a' , max(max(vacation[x].a, vacation[x].b),vacation[x].c)};
    }
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int a, b, c;


    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        vacation.push_back({a, b, c});
    }


    cout << makechoise(n).value;

    return 0;
}