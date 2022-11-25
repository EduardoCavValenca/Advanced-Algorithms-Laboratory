#include <bits/stdc++.h>
using namespace std;

void print_result(bool turn_1){
    if (turn_1)
        cout << "Second" << endl;
    else
        cout << "First" << endl;
}



int main(){
    int test_cases;
    cin >> test_cases;


    while(test_cases--) {
        int size;
        cin >> size;

        int counter = 0;

        vector<int> input(size);
        for (auto &value: input) {
            cin >> value;
            if (value == 1)
                counter++;
        }

        bool turn_1;

        if (size == 1 || counter == 0) {
            turn_1 = false;
            print_result(turn_1);
            continue;
        }
        if (counter == size) {
            turn_1 = !bool(size % 2);
            print_result(turn_1);
            continue;
        }
        for (int i = 0; i < size; i++){
            if (input[i] > 1) {
                turn_1 = i % 2;
                print_result(turn_1);
                break;
            }
        }

    }

}