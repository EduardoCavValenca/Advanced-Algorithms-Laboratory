#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int possible_lengths(vector<int> &array, vector<int> &longest_subsequence){

    int maximum = 1;

    for(int i = (int) array.size() - 2; i >= 0; i--){
        for(int j = i+1; j < (int) longest_subsequence.size();j++)
            if (array[i] < array[j])
                longest_subsequence[i] = max(longest_subsequence[i], 1 + longest_subsequence[j]);

        if (longest_subsequence[i] > maximum)
            maximum = longest_subsequence[i];
    }

    return maximum;
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

    cout << possible_lengths(array,longest_subsequence) << endl;

    return 0;
}