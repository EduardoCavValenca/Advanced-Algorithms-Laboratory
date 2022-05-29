#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string lcs(string& str1, string& str2)
{
    int size1 = (int) str1.size();
    int size2 = (int) str2.size();

    int matrix[size1 + 1][size2 + 1];

    for (auto i = 0; i <= size1; i++) {
        for (auto j = 0; j <= size2; j++) {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;

            else if (str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1] + 1;

            else
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }

    int lin =  size1;
    int col =  size2;

    string result;
    while(true){

        if(matrix[lin][col] == 0)
            break;

        if(matrix[lin - 1][col] == matrix[lin][col - 1]) {
            if(matrix[lin][col] > matrix[lin-1][col - 1]){
                result.push_back(str2[col-1]);
                lin--;
                col--;
            }
            else
                col--;

        }
        else if(matrix[lin-1][col] > matrix[lin][col-1])
            lin--;

        else
            col--;
    }
    reverse(result.begin(),result.end());

    return result;
}

int main() {

    string str1,str2;

    getline(cin, str1);
    getline(cin, str2);

    cout << lcs(str1,str2) <<endl;

    return 0;
}