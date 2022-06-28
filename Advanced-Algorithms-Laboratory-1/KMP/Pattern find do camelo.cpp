#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void pattern_find(const string& str,const string& pattern){

    vector<int> ans;

    size_t found = str.find(pattern);
    while(found != string::npos){
        ans.push_back(found + 1);
        found = str.find(pattern, found + 1);
    }


    if(!ans.empty()){
        cout << ans.size() << endl;
        for (auto &value : ans)
            cout << value << " ";
        cout << endl;
    }
    else
        cout << "Not Found" << endl;

    cout << endl;

}



int main() {

    int n;
    cin >> n;

    string str;
    string pattern;
    for (auto i = 0; i < n; i++){
        cin >> str;
        cin >> pattern;
        pattern_find(str,pattern);
    }

    return 0;
}