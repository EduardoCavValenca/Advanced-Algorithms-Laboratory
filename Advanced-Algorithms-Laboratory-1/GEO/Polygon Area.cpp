#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int polygonArea(vector<long long int>& X, vector<long long int>& Y, int n)
{
    // Initialize area
    long long int area = 0.0;

    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;
    }

    // Return absolute value
    return area;
}

int main()
{
    int queries_n;
    cin >> queries_n;

    vector<long long int> X(queries_n),Y(queries_n);

    for (auto i = 0; i < queries_n; i++)
        cin >> X[i] >> Y[i];
    
    cout << abs(polygonArea(X,Y,queries_n));

    return 0;
}