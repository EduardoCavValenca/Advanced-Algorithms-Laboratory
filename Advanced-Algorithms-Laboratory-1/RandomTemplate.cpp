#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {

    int read_times;
    string first_line;

    getline(cin,first_line);
    read_times = stoi(first_line);

    for(auto z = 0; z < read_times; z++){
        string line;
        getline(cin,line);
        stack<int> stack_mut;

//
        stack<int> stack_add;
        stack_add.push(0);

        int current_element = 0;
        char operation= '+';

        for (long unsigned int i = 0; i < line.length(); i++){

            if ('0'<= line[i] and line[i] <= '9'){
                current_element = current_element * 10 + line[i] - '0';
            }

            if ( i == line.length() - 1 or line[i] == '+' or line[i] == '*'){

                if (operation == '+'){
                    stack_mut.push(current_element);

                    int stackTop = stack_add.top();
                    stack_add.pop();
                    stack_add.push(stackTop + current_element);
                }
                else{
                    stack_add.push(current_element);

                    int stackTop = stack_mut.top();
                    stack_mut.pop();
                    stack_mut.push(stackTop * current_element);

                }
                operation = line[i];
                current_element = 0;
            }

        }

        long unsigned int max_result = 1;
        long unsigned int min_result = 0;

        while(!stack_mut.empty()){
            min_result += stack_mut.top();
            stack_mut.pop();
        }

        while(!stack_add.empty()){
            max_result *= stack_add.top();;
            stack_add.pop();
        }

        cout << "The maximum and minimum are " << max_result << " and " << min_result << "."<<endl;

    }

    return 0;
}