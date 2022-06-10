#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int number;
    cin >> number;

    if (number == 1){
        cout << "NO";
        return 0;
    }

    for (auto i = number/2 - 1; i > 1; i--){
        if (number % i == 0){
            cout << "NO";
            return 0;
        }

    }
    cout << "YES";
    return 0;
}