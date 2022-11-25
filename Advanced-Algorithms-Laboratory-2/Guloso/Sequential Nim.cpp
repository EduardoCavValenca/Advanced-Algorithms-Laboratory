#include <bits/stdc++.h>
using namespace std;

void print_result(bool winner_1){
    if (winner_1)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}

bool get_winner(){

    int size;
    cin >> size;

    int counter_1 = 0;
    int first_greater_index = -1;

    int value;
    for(int i = 0; i < size; i++){
        cin >> value;
        if(value == 1)
            counter_1++;
        if(value > 1 && first_greater_index < 0)
            first_greater_index = i;
    }

    if(counter_1 == 0)
        return true;

    if(counter_1 == size)
        return size % 2;

    return !bool(first_greater_index % 2);
}

int main(){
    int test_cases;
    cin >> test_cases;

    while(test_cases--)
        print_result(get_winner());

    return 0;

}