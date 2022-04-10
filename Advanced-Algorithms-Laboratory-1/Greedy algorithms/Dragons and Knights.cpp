#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {

    while (true) {

        int dragon_heads, knights;
        cin >> dragon_heads >> knights;

        if (dragon_heads == 0 && knights == 0){
            break;
        }

        vector<int> dragons_vec;
        vector<int> knights_vec;

        for (auto i = 0; i < dragon_heads; i++) {
            int value;
            cin >> value;
            dragons_vec.push_back(value);
        }

        for (auto i = 0; i < knights; i++) {
            int value;
            cin >> value;
            knights_vec.push_back(value);
        }

        sort(dragons_vec.begin(), dragons_vec.end());
        sort(knights_vec.begin(), knights_vec.end());

        int knight_index = 0;

        int cost = 0;
        bool doomed = false;
        for (auto i = 0; i < dragon_heads; i++){
            while (knight_index < knights and  knights_vec[knight_index] < dragons_vec[i]){
                knight_index++;
            }
            if (knight_index == knights){
                doomed = true;
                break;
            }
            cost += knights_vec[knight_index];
            knight_index++;
        }

        if (doomed){
            cout << "Loowater is doomed!" << endl;
        }
        else{
            cout << cost << endl;
        }

    }
    return 0;
}