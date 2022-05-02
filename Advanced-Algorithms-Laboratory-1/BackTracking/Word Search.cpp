#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};


int m,n;
int movements[4][2] = {{0,1}, {0,-1}, {1,0,},{-1,0}};
unordered_map<pair<int, int>, bool, hash_pair> visited;
int target;


bool find_word(int i,int j, char* word, int index, char** matrix){
    if (visited.count(make_pair(i,j)) or matrix[i][j] != word[index])
        return false;

    if (index == target)
        return true;

    visited[make_pair(i,j)] = true;

    for (auto & mov: movements){
        if(i + mov[0] >= m or i + mov[0] < 0)
            continue;
        if(j + mov[1] >= n or j + mov[1] < 0)
            continue;

        if(find_word(i+mov[0],j+mov[1],word,index + 1,matrix))
            return true;
    }

    visited.erase(make_pair(i,j)); // backtracking

    return false;
}

int main() {

    cin >> m >> n;
    char new_val;

    char **matrix;
    matrix = new char *[m];
    for(int i = 0; i <m; i++)
        matrix[i] = new char[n];

    for (int i = 0; i <m; i++){
        for (int j = 0; j <n; j++){
            cin >> new_val;
            matrix[i][j] = new_val;
        }
    }

    int tam;
    cin >> tam;
    target = tam - 1;

    char word[tam];
    for (auto &letter : word){
        cin >> new_val;
        letter = new_val;
    }


    for(auto i = 0; i< m; i++){
        for(auto j = 0; j< n; j++){
            if(find_word(i,j,word,0, matrix)) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";

    return 0;
}