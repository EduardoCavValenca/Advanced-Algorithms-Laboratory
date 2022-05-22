#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,W;
long long int *values;
long long int *weights;
long long int **max_profit;

long long int backpack_solve(){

    for (auto i = 0; i <= N; i++){
        for (auto w = 0; w <= W; w++){
            if (i == 0 || w == 0)
                max_profit[i][w] = 0;
            else if (w >= weights[i]) {
                max_profit[i][w] = max(values[i] + max_profit[i - 1][w - weights[i]], max_profit[i - 1][w]);
            }
            else
                max_profit[i][w] = max_profit[i-1][w];
        }
    }

    return max_profit[N][W];
}

int main() {

    cin >> N >> W;

    max_profit = new long long int* [N+1];
    for (auto i = 0; i < N+1; i++)
        max_profit[i] =  new long long int [W+1];

    values = new long long int [N+1];
    weights = new long long int [N+1];

    values[0] = 0;
    weights[0] = 0;

    for(auto i = 0; i < N; i++){
        cin >> weights[i+1] >> values[i+1];
    }

    cout << backpack_solve() <<endl;

    return 0;
}