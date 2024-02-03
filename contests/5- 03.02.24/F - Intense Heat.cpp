#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;


    int total_days; cin >> total_days;
    int segment_size; cin >> segment_size;

    vector<int> temperature;

    int a;
    for (int i = 0; i < total_days; i++) {
        cin >> a;

        temperature.push_back(a);
    }
    
    vector<double> averages;
    double average;
    int sum;

    vector<int> prefix_sum(total_days+1);

    prefix_sum[0] = 0;
    for (int i = 1; i < total_days+1; i++) {
        prefix_sum[i] = temperature[i-1] + prefix_sum[i-1];
    }

    // for (auto e:prefix_sum) cout << e << endl;

    segment_size--;
    while (segment_size++ != total_days) {
        for (int i = 0; i <= total_days-segment_size; i++) {
            
            
            sum = prefix_sum[segment_size+i] - prefix_sum[i];

            // sum = 0;
            // for (int j = i; j < segment_size+i; j++) {
            //     sum += temperature[j];
            // }

            // cout << "SUM" << i << ": " << sum << endl;

            average = double(sum)/double(segment_size);
            averages.push_back(average);
        }
    }

    sort(averages.begin(), averages.end());

    cout << averages[averages.size()-1];

    return 0;
}