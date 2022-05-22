#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int **matrix;
int **decisions;

int recursive(int level, int prev){
    if(level == N) return 0;

    if(decisions[level][prev] != -1)
        return decisions[level][prev];

    int ans = 0;
    for(int j = 0; j < 3; j++){
        if(j != prev){
            ans = max(recursive(level+1,j) + matrix[level][j], ans);
        }
    }
    decisions [level][prev] = ans;
    return ans;
}

int main() {

    cin >> N;

    matrix = new int *[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new int[3];

    decisions = new int *[N];
    for(int i = 0; i < N; i++)
        decisions[i] = new int[3];

    for(auto i = 0; i < N; i++)
        for(auto j = 0; j < 3; j++) {
            cin >> matrix[i][j];
            decisions[i][j] = -1;
        }

    cout<<max({recursive(0,0),recursive(0,1),recursive(0,2)})<<endl;

    return 0;
}