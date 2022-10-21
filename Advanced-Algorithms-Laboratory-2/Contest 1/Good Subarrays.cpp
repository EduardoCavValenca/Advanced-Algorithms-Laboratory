#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t number_of_tests;
    cin >> number_of_tests;

    while(number_of_tests--) {
        size_t array_length;
        cin >> array_length;

        long long int sum = 0;
        long long int result = 0;
        unordered_map<int,int> previous_sums;
        previous_sums[0]++; //Simulate a 0 in index -1
        char read;
        int read_int;

        for (auto i = 0; i < array_length; i++) {
            cin >> read;
            read_int = int(read) - '0';

            sum += read_int;
            result += previous_sums[sum - (i + 1)];
            previous_sums[sum - (i + 1)]++;
        }

        cout << result << endl;

    }
}