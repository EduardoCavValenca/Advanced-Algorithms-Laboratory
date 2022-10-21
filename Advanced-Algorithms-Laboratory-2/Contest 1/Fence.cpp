#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t array_length;
    cin >> array_length;

    size_t n_planks;
    cin >> n_planks;

    size_t total;
    vector<size_t> mov_average;
    vector<size_t> values(array_length);

    for (auto i = 0; i < array_length; i++){
        cin >> values[i];
        total += values[i];

        if (i >= n_planks) total -= values[i - n_planks];

        if (i >= n_planks - 1)
            mov_average.push_back(total);
    }
    cout << distance(begin(mov_average), min_element(begin(mov_average), end(mov_average))) + 1;
}