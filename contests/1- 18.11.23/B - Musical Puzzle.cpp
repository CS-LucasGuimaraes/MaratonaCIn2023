#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len, len_s;
    string str;

    cin >> len;

    for (int i = 0; i < len; i++) {
        cin >> len_s;
        cin >> str;
        map<string, int> freq;

        for (int j = 1; j < len_s; j++) {
            string concat;
            concat += str[j-1];
            concat += str[j];
            if (freq.find(concat) == freq.end()) {
                freq[concat] = 1;
            }
            else {
                freq[concat]++;
            }
        }
    cout << freq.size() << '\n';
    }

    return 0;
}