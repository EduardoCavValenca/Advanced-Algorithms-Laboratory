#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t number_of_tests;
    cin >> number_of_tests;
    string trash;

    while(number_of_tests--){
        size_t array_length;
        cin >> array_length;

        int value;
        int root;
        bool result = false;

        for(auto i = 0; i < array_length; i++) {
            cin >> value;
            root = sqrt(value);
            if (root * root != value) {
                result =  true;
                getline(cin, trash);
                break;
            }
        }
        if (result) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}