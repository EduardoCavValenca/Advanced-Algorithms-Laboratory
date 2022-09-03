#include <bits/stdc++.h>
using namespace std;

void dfs(string& input, int idx, string cur){
    if(cur.length() == input.length()){
        cout << cur << endl;
        return;
    }
    for(int i = 0; i <= cur.length(); i++)
        dfs(input, idx+1, cur.substr(0,i) + input[idx]+  cur.substr(i));
}

int main()
{
    string input;
    bool que_porra = false;

    while(cin >> input){
        if(que_porra)
            cout << endl;
        que_porra = true;
        dfs(input,0,"");
    }
}