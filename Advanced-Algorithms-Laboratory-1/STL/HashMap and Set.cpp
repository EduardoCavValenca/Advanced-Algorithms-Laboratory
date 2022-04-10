#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct comp
{
    template<typename T>
    bool operator()(const T &l, const T &r) const
    {
        if (l.second.size() != r.second.size()) {
            return l.second.size() > r.second.size();
        }

        return l.first < r.first;
    }
};


int main() {

    map<string,string> seen;
    set<string> removed;
    map<string, set<string>> map;
    string last_key;

    while (true) {

        string input;
        getline (cin,input);

        if (input == "0") {
            break;

        } else if (input == "1") {

            set<pair<string, set<string>>, comp> set(map.begin(), map.end());
            for (auto const &pair: set) {
                cout << pair.first << " " << pair.second.size() << endl;
            }
            map.clear();
            removed.clear();
            seen.clear();

        } else {

            if (removed.count(input)){
                continue;
            }

            if(seen.count(input)){
                if (seen[input] != last_key){
                    map[seen[input]].erase(input);
                    removed.insert(input);
                    continue;
                }
            }

            bool new_key = true;
            for (auto const &letter: input) {
                if ( letter <= 122 and letter >=97)
                    new_key = false;
            }
            if (new_key){
                last_key = input;
                map[last_key];
            }
            else{
                map[last_key].insert(input);
                seen[input] = last_key;
            }


        }
    }

    return 0;
}