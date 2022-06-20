#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int divisible_by_3(vector<int>& array, int n){

    int maximum;
    unordered_map<int, int> counter;

    for (auto i = 0; i < n; i++)
        counter[array[i]%3]++;

    maximum = counter[0];

    if (counter[2] > counter[1])
        tie(counter[2], counter[1]) = make_tuple(counter[1], counter[2]);

    maximum += counter[2];
    counter[1] -= counter[2];
    maximum += counter[1]/3;

    return maximum;
}



int main() {

    int times;
    cin >> times;

    for (auto i = 0; i < times; i++){
        int n;
        cin >> n;
        vector<int> array(n);

        int dummy;
        for (auto j = 0; j < n; j++){
            cin >> dummy;
            array[j] = dummy;
        }
        cout << divisible_by_3(array, n) << endl;
    }

    return 0;
}