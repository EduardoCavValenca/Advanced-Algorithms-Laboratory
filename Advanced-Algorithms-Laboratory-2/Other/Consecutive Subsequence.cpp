//NAO RODA NO VJUDGE NAO COPIE MUSSATTO
//MAS FOI MINHA SOLUCAO ENTAO SALVEI

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> get_indexes(vector<int> &array, vector<int> &longest_subsequence){

    int return_index = 0;
    size_t max_length = 0;

    vector<vector<int>> indexes(array.size());

    for(int i = (int) array.size() - 1; i >= 0; i--){
        for(int j = i+1; j < (int) longest_subsequence.size();j++) {
            if (array[i] - array[j] == -1) {
                longest_subsequence[i] = max(longest_subsequence[i], 1 + longest_subsequence[j]);
                if(indexes[j].size() > indexes[i].size()){
                    indexes[i].clear();
                    copy(indexes[j].begin(), indexes[j].end(), back_inserter(indexes[i]));
                    if(indexes[i].size() > max_length){
                        return_index = i;
                        max_length = indexes[i].size();
                    }
                }

            }
        }

        indexes[i].push_back(i+1);

    }

    cout << longest_subsequence[return_index] << endl;

    reverse(indexes[return_index].begin(), indexes[return_index].end());

    return indexes[return_index];
}

int main() {

    int length;
    cin >> length;

    vector<int> array(length);
    vector<int> longest_subsequence(length);

    for (auto i = 0; i < length; i++) {
        cin >> array[i];
        longest_subsequence[i] = 1;
    }

    if (length == 1) {
        cout << 1 << endl;
        cout << 0 << endl;
    }
    else{
        for(const auto& index : get_indexes(array, longest_subsequence))
            cout << index << " ";
        cout << endl;
    }

    return 0;
}