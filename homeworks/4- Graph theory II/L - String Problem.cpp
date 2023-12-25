#include <bits/stdc++.h>

#define INF 2601

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t; 
    
    cin >> s >> t;
    int changes; cin >> changes;
    
    char a, b;
    int weight;

    vector<vector<int>> matrix(26, vector<int>(26, INF));

    for (int i = 0; i < changes; i++) {
        cin >> a >> b; cin >> weight;
        a -= 97; b -= 97;

        matrix[a][b] = min(matrix[a][b], weight);
    }

    for (int i = 0; i < 26; i++) {
        matrix[i][i] = 0;
    }
    
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
            }
        }
    }

    if (s.size() != t.size()) {
        cout << -1;
        return 0;
    }

    int len = s.size();

    string answer;
    int sum = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == t[i]) {
            answer.push_back(s[i]);
            continue;
        }

        a = s[i] - 97;
        b = t[i] - 97;
        
        vector<int> sum_row(26);
        int min = INF;
        char min_char;

        for (int j = 0; j < 26; j++) {
            sum_row[j] = matrix[a][j] + matrix[b][j];
            if (sum_row[j] < min) {
                min = sum_row[j];
                min_char = j + 97;
            }
        }

        if (min >= INF) {
            cout << -1;
            return 0;
        }

        answer.push_back(min_char);
        sum += min;
    }
    
    
    cout << sum << '\n' << answer;

    return 0;
}