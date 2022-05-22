#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int possible_costs(vector<int> &array, vector<int> &costs){

    int size = (int) array.size();

    costs[size - 1] = 0; //target

    for(int i = size - 2; i >= 0; i--){ //Go backwards
        if (i + 1 < size)
            costs[i] = costs[i+1] + abs(array[i+1] - array[i]);
        if (i + 2 < size)
            costs[i] = min(costs[i], costs[i+2] + abs(array[i+2] - array[i]));
    }

    return costs[0]; //Minimum cost
}

int main() {

    int length;
    cin >> length;

    vector<int> array(length);
    vector<int> costs(length);

    for (auto i = 0; i < length; i++) {
        cin >> array[i];
        costs[i] = INT_MAX;
    }

    cout << possible_costs(array,costs) << endl;

    return 0;
}