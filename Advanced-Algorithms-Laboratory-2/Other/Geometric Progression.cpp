//NAO RODA NO VJUDGE NAO COPIE MUSSATTO
//MAS FOI MINHA SOLUCAO ENTAO SALVEI


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int length, ratio;
    cin >> length >> ratio;

    vector<int> values(length);

    for (auto& value : values)
        cin >> value;

    unordered_map<int, int> um_numbers_forward;
    unordered_multiset<int> ums_numbers_forward;
    unordered_map<int, vector<int>> um_position_forward;

    int result = 0;

    for (int i = (int) values.size() - 1; i >= 0; i--){

        um_numbers_forward[i] = ums_numbers_forward.count(values[i]*ratio);
        ums_numbers_forward.insert(values[i]);

        for(const auto& index : um_position_forward[values[i]*ratio])
            result += um_numbers_forward[index];

        um_position_forward[values[i]].push_back(i);


    }

    cout << result << endl;

    return 0;
}
