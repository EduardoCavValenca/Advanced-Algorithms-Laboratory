//Tentando usar tecnicas avancadas

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int_fast64_t lds(const vector<int_fast16_t> &missiles){

    vector<int_fast64_t> dp(missiles.size());
    dp[0] = 1;

    for (size_t i = 1; i < missiles.size(); i++) {
        dp[i] = 1;
        for (size_t j = 0; j < i; j++)
            if (missiles[i] < missiles[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }

    return *max_element(dp.begin(), dp.end());
}


int main() {

    uint_fast64_t counter = 1;
    int_fast16_t value;
    cin >> value;

    bool presentation_fucking_error = false;

    while(value != -1){

        vector<int_fast16_t> missiles;
        while(value != -1){
            missiles.emplace_back(value);
            cin >> value;
        }
        if (presentation_fucking_error) cout << endl;
        presentation_fucking_error = true;
        cout << "Test #"<<counter<<":\n  maximum possible interceptions: " << lds(missiles)  << endl;
        counter++;
        cin >> value;
    }
    return 0;
}
