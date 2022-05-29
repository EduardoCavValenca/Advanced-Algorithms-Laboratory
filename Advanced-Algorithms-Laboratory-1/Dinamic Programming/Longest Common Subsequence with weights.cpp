#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lcs_with_weights(string& str1, string& str2, vector<int>& weights)
{
    int size1 = (int) str1.size();
    int size2 = (int) str2.size();

    int **matrix;
    matrix = new int* [size1+1];
    for (auto i = 0; i <= size1; i++)
        matrix[i] = new int[size2+1];

    for (auto i = 0; i <= size1; i++) {
        for (auto j = 0; j <= size2; j++) {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;

            else if (str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1] + weights[((int) str2[j-1])-97];

            else
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }

    return matrix[size1][size2];

}

int main() {

    int size1,size2;
    cin >> size1 >> size2;

    vector<int> weights(26);
    for(auto i = 0; i < 26; i++)
        cin >> weights[i];

    string str1,str2;
    char dummy;
    for(auto i = 0; i < size1; i++) {
        cin >> dummy;
        str1.push_back(dummy);
    }
    for(auto i = 0; i < size2; i++) {
        cin >> dummy;
        str2.push_back(dummy);
    }
    
    cout << lcs_with_weights(str1,str2,weights) <<endl;

    return 0;
}