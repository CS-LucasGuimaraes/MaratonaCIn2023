#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    deque<string> dq;

    int len;

    cin >> len;

    cin >> str;
    dq.push_front(str);

    for (int i = 0; i < len-1; i++) {
        cin >> str;
        if (lexicographical_compare(dq.back().begin(), dq.back().end(), str.begin(), str.end())){
            dq.push_front(str);
        }
        else {
            dq.push_back(str);
        }
    }

    while (dq.empty() == false)
    {
        cout << dq.back();
        dq.pop_back();
    }

    return 0;
}

/*
Erro quando a string é maior que o dq.back(). Nesses casos, o dq.back() pode ser analisado como lexicograficamente menor mesmo que faça mais sentido colocar-lo depois. Nesses casos, é preciso analisar o elemento após o dq.back(), e ver se dq.back()+[dq.back()+1] é lexicograficamente menor que a string.
*/ 