#include <bits/stdc++.h>
using namespace std;

int main(){
    int test_cases;
    cin >> test_cases;


    while(test_cases--) {
        string input;
        cin >> input;

        for(int i = 0; i < input.size(); i++) {
            //bob
            if (i % 2) {
                if (input[i] == 'z')
                    input[i] = 'y';
                else
                    input[i] = 'z';
            } else {
                if (input[i] == 'a')
                    input[i] = 'b';
                else
                    input[i] = 'a';
            }
        }
        cout << input << endl;
    }

}