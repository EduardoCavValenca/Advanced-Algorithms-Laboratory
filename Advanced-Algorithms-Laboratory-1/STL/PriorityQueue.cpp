#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Job {

public:
    int priority;
    int order;

    Job(int priority, float order): priority(priority), order(order)
    {
    }
};

bool operator<(const Job& j1, const Job& j2)
{

    return j1.priority <= j2.priority;
}


int main() {

    int read_times, tam;

    cin >> read_times;

    for(auto i = 0; i<read_times;i++){
        int q[10] = {};
        int variable = 0;
        int job = 0;
        cin >> tam >> job;
        queue<Job> pq;
        for( int j = 0; j < tam; j++){
            cin >> variable;
            q[variable]++;
            pq.push(Job(variable,j));
        }
        int counter = 1;
        while(true){
            auto current_job = pq.front();
            pq.pop();
            bool pushed = false;
            for(auto k = current_job.priority+1; k < 10; k++){
                if (q[k] > 0){
                    pushed = true;
                    pq.push(current_job);
                    break;
                }
            }

            if (!pushed) {
                if (current_job.order == job) {
                    cout << counter;
                    break;
                }
                else{
                    q[current_job.priority]--;
                    counter++;
                }

            }

        }
        if(i != read_times - 1)
            cout << endl;
    }
    return 0;
}
