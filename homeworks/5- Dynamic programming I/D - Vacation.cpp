    #include <bits/stdc++.h>

    using namespace std;

    struct actv{
        int a, b, c;  
    };

    struct choice{
        int a, b, c;
        int value;
    };

    vector<choice> bestchoice(1e5, {-1, -1, -1, -1});
    vector<actv> vacation;

    choice makeChoice(int x) {
        if (bestchoice[x].value != -1) return (bestchoice[x]);

        if (x == 0) {
            return bestchoice[x] = {vacation[0].a, vacation[0].b, vacation[0].c, max(max(vacation[0].a, vacation[0].b), vacation[0].c)};
        }

        choice chc;

        chc.a = max(vacation[x].a + makeChoice(x-1).b, vacation[x].a + makeChoice(x-1).c);
        chc.b = max(vacation[x].b + makeChoice(x-1).a, vacation[x].b + makeChoice(x-1).c);
        chc.c = max(vacation[x].c + makeChoice(x-1).a, vacation[x].c + makeChoice(x-1).b);

        return bestchoice[x] = {chc.a, chc.b, chc.c, max(max(chc.a, chc.b), chc.c)};
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


        cout << makeChoice(n-1).value;

        return 0;
    }