#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int number;
    cin >> number;

    vector<int> divisors;

    for (auto i = 1; i*i <= number; i++){
        if (number % i == 0){
            cout << i << " ";
            divisors.push_back(i);
        }
    }

    if (divisors.back() * divisors.back() == number)
        divisors.pop_back();

    for (int i = divisors.size() - 1; i >= 0; i--)
            cout << number/divisors[i] << " ";

    return 0;
}