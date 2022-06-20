#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minimum_tree_distance(vector<int>& array, int n){

    int minimum = INT_MAX;
    int start = array[0];
    int end = array[n-1];

    for (auto i = 0; i < n - 1; i++) {
        array[i] = array[i + 1] - array[i];
        minimum = min(array[i], minimum);
    }

    while(minimum > 1){
        bool flag = false;
        for (auto i = 1; i < n - 1; i++) {
            if (array[i] % minimum != 0) {
                flag = true;
                break;
            }
        }
        if (flag)
            minimum /= 2;
        else
            break;
    }

    int total_length = end - start;
    int total_trees = total_length/minimum + 1;
    int needed_trees = total_trees - n;

    return needed_trees;
}



int main() {

    int n_trees;
    cin >> n_trees;

    vector<int> array(n_trees);
    for (auto i = 0; i < n_trees; i++)
        cin >> array[i];

    cout << minimum_tree_distance(array, n_trees) << endl;

    return 0;
}