#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t number_of_tests;
    cin >> number_of_tests;

    tuple<bool, bool, bool> confidence;
    auto& [Petya, Vasya, Tonya] = confidence;
    int result = 0;

    while(number_of_tests-- && cin >> Petya >> Vasya >> Tonya)
        result += apply([](auto ... value ){ return ( value + ... ); }, confidence) >= 2;
    cout << result;
}