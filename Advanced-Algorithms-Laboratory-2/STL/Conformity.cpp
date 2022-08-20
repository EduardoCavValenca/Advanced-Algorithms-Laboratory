#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {

    int read;
    cin >> read;

    while (read){
        int maximum = 0;
        int total = 0;
        map<vector<int>, int> popularity;

        for (auto students = 0; students < read; students++){
            vector<int> grades(5);
            for (int grade = 0; grade < 5; grade++)
                cin >> grades[grade];
            sort(grades.begin(), grades.end());

            popularity[grades]++;

            if (popularity[grades] == maximum)
                total += maximum;

            if (popularity[grades] > maximum){
                maximum = popularity[grades];
                total = maximum;
            }

        }
        cout << total << endl;

        cin >> read;
    }
    return 0;
}