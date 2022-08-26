#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool compare_function(const pair <double, double> &n1, const pair <double, double> &n2){
    if (n1.first != n2.first)
        return n1.first < n2.first;
    return n1.second > n2.second;
}

int main() {

    int n;
    double l, w;

    while (cin >> n >> l >> w){

        vector<pair<double, double>> ranges;

        double position, radius;
        for (int i = 0; i < n; i++) {
            cin >> position >> radius;

            if (radius > w/2) {
                double effective_range = sqrt(radius*radius - (w/2)*(w/2));
                ranges.push_back(make_pair(position - effective_range, position + effective_range));
            }
        }

        sort(ranges.begin(), ranges.end(), compare_function);

        bool fail = false;
        double left_point = 0;
        int total = 0;

        for (int i = 0; i < (int) ranges.size() and left_point < l; i++){

            if (ranges[i].first > left_point){
                fail = true;
                break;
            }

            double greater = ranges[i].second;
            int greater_index = i;

            for (int j = i + 1; j < (int) ranges.size() and ranges[j].first <= left_point; j++) {
                if (greater < ranges[j].second) {
                    greater_index = j;
                    greater = ranges[j].second;
                }
            }

            left_point =  greater;
            i = greater_index;

            total++;

        }

        if (left_point < l)
            fail = true;

        if (fail)
            cout << -1 << endl;
        else
            cout << total << endl;

    }


    return 0;
}