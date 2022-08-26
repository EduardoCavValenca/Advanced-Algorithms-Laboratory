#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    while(test_cases--){

        int num_turtles;
        cin >> num_turtles;

        vector<string> wrong(num_turtles);
        vector<string> right(num_turtles);

        getchar();
        for (int i = 0; i < num_turtles; i++)
            getline(cin, wrong[i]);

        for (int i = 0; i < num_turtles; i++)
            getline(cin, right[i]);

        int wrong_index = num_turtles - 1;
        int right_index = num_turtles - 1;

        while (wrong_index >= 0){
            if (wrong[wrong_index] == right[right_index] )
                right_index--;
            wrong_index--;
        }
        while (right_index >= 0)
            cout << right[right_index--] << endl;

        cout << endl;

    }

    return 0;
}