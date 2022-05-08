#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int bs(vector<int> &array, int low, int high, int goal){

    int mid;

    while( low < high){
        mid = (low + high)/2;

        if (array[mid] <= goal)
            low = mid + 1;
        else
            high = mid;
    }
    return high;
}

void possible_sums(vector<int> &array,int start, int end, unordered_set<int> &results){

    int total_sum;
    total_sum = accumulate(next(array.begin(),start),next(array.begin(),end + 1),0);
    results.insert(total_sum);

    if (array[start] == array[end]) return; //loop

    int mid = (array[start] + array[end])/2;

    int pivot = bs(array,start,end,mid);

    possible_sums(array,start,pivot - 1,results);
    possible_sums(array,pivot,end,results);

}

int main() {

    int new_val;

    int read_times;
    cin >> read_times;

    int len;
    int tests;

    while(read_times--){

        cin >> len >> tests;

        vector<int> array(len);
        unordered_set<int> results;

        for (auto i = 0; i < len; i++){
            cin >> array[i];
        }

        sort(array.begin(), array.end());

        possible_sums(array,0,len-1,results);

        for (auto i = 0; i < tests; i++){
            cin >> new_val;
            if (results.count(new_val))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

    }

    return 0;
}