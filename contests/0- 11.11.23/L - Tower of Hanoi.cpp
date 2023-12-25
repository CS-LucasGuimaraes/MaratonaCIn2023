#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> answ;

void hanoi(int n, int start, int end) {
    if (n == 1) answ.push_back({start, end}); //caso base
    else {
        int other = 6 - (start+end);

        hanoi(n-1, start, other); // resolve para n-1 trocando a final pela auxiliar
        answ.push_back({start, end}); // coloca a maior no lugar certo
        hanoi(n-1,other,end); // resolve ao contrário pra voltar todo mundo da auxiliar pro final
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;

    hanoi(n,1,3);

    cout << answ.size() << '\n';
    for (auto [start, end]: answ) cout << start << ' ' << end << '\n';

    return 0;
}