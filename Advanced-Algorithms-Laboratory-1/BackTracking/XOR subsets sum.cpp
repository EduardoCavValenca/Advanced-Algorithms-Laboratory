#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> input;
int total_sum = 0;
int tam;

void subsets(int index, vector<int>& vec, int current_xor){

    total_sum += current_xor;

    if (index == tam) return;
    for (int i = index; i < tam; i++){
        vec.push_back(input[i]);
        current_xor ^= input[i];

        subsets(++index,vec,current_xor);

        current_xor ^= input[i];
        vec.pop_back();
    }
}


int main() {

    int read_times;
    int new_val;
    cin >> read_times;

    for(auto z = 0; z < read_times; z++){
        cin >> new_val;
        input.push_back(new_val);
    }

    tam = read_times;
    vector<int> sets;
    int current_xor = 0;

    subsets(0,sets,current_xor);

    cout << total_sum << endl;

    return 0;
}