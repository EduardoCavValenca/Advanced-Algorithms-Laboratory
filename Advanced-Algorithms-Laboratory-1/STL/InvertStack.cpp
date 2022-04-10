#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void print_stack(stack<int> stack){
    if (stack.empty()){
        return;
    }
    cout << stack.top() << endl;
    stack.pop();
    print_stack(stack);
}

int main() {

    int read_times, tam;

    cin >> read_times;

    for(auto i = 0; i<read_times;i++){
        stack<int> stack;
        int variable = 0;
        cin >> tam;
        for( auto j = 0; j < tam; j++){
            cin >> variable;
            stack.push(variable);
        }
        print_stack(stack);
        if(i != read_times - 1)
            cout << endl;
    }
    return 0;
}
