#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {

    int read_times;
    cin >> read_times;

    for (auto i=0; i<read_times; i++){
        int number_snowflakes;
        cin >> number_snowflakes;

        map<int,int> seen;
        map<int,int> track;

        int max_value = 0;
        int total_max = 0;
        for (auto j=0; j<number_snowflakes; j++){
            int snow_flake;
            cin >> snow_flake;

            if (seen.count(snow_flake)) {
                total_max = max(total_max,max_value);

                auto it = track.cbegin();
                auto next_it = it;

                while(true) {
                    ++next_it;
                    if (it->first == seen[snow_flake]) {
                        seen.erase(it->second);
                        track.erase(it);
                        break;
                    }
                    seen.erase(it->second);
                    track.erase(it);
                    it = next_it;
                }
                track[j] = snow_flake;
                seen[snow_flake]= j;
                max_value = seen.size();

            }
            else{
                max_value++;
                seen[snow_flake]= j;
                track[j] = snow_flake;
            }
        }
        total_max = max(total_max,max_value);

        cout << total_max << endl;
//        for (auto const &pair: same_snowflake) {
//            std::cout << "{" << pair.first << ": " << pair.second << "}\n";
//        }
    }

    return 0;
}