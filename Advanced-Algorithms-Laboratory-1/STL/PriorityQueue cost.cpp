#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {

    while (true) {

        int read_times;
        cin >> read_times;

        if (read_times == 0){
            break;
        }

        priority_queue <int, vector<int>, greater<int> > pq;
        for (auto i = 0; i < read_times; i++) {
            int value;
            cin >> value;
            pq.push(value);
        }

        int cost = 0;

        while(true){
            int val1 = pq.top();
            pq.pop();
            int val2 = pq.top();
            pq.pop();

            int current_cost = val1 + val2;

            cost += current_cost;

            if(pq.empty()){
                break;
            }
            else{
                pq.push(current_cost);
            }
        }

        cout << cost << endl;
    }
    return 0;
}