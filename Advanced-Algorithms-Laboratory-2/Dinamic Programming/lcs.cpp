
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lcs(vector<char>&suggestion_1, vector<char>&suggestion_2){

    size_t s1_size = suggestion_1.size();
    size_t s2_size = suggestion_2.size();

    vector<vector<int>> dp(s1_size + 1, vector<int>(s2_size + 1));

    for (size_t i = 0; i <= s1_size; i++){
        for (size_t j = 0; j <= s2_size; j++){

            if ( !i || !j ) {
                dp[i][j] = 0;
                continue;
            }

            if (suggestion_1[i-1] == suggestion_2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[s1_size][s2_size];
}



int main() {

    string input;
    size_t counter = 0;

    while (getline(cin,input) && input[0] != '#') {
        vector<char> suggestion_1(input.begin(), input.end());
        getline(cin,input);
        vector<char> suggestion_2(input.begin(), input.end());
        counter++;
        cout << "Case #"<< counter <<": you can visit at most "<< lcs(suggestion_1, suggestion_2) << " cities." << endl;
    }

    return 0;
}
