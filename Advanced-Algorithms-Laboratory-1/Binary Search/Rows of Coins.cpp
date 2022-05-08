#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int bs(long int low,long int high,long int coins){

    long int mid;
    long int current_coins;

    while (low <= high){
        mid = low + (high - low)/2;

        current_coins = (1+mid)*mid/2;

        if ( current_coins == coins){
            return mid;
        }
        else if( current_coins > coins){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return high;
}


int main() {

    long int coins;
    cin >> coins;

    cout << bs(1,coins,coins) << endl;

    return 0;
}