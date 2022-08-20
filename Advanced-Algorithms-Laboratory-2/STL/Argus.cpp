#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int id, period, current_time;

    node(int id, int period, int current_time){
        this->id = id;
        this->period = period;
        this->current_time = current_time;
    }
};


struct compare_node{
    bool operator()(node const& n1, node const& n2)
    {
        if (n1.current_time == n2.current_time){
            return n1.id > n2.id;
        }
        return n1.current_time > n2.current_time;
    }
};



int main() {

    string word;
    int id, period;

    cin >> word;

    priority_queue< node, vector<node>, compare_node> pq;

    while (word != "#"){
        cin >> id >> period;
        pq.push(node(id, period, period));
        cin >> word;
    }

    int quantity;
    cin >> quantity;

    while(quantity--){
        cout << pq.top().id << endl;
        pq.push(node(pq.top().id, pq.top().period, pq.top().current_time + pq.top().period));
        pq.pop();
    }

    return 0;
}