#include <iostream>
#include <bits/stdc++.h>


using namespace std;

void preprocess(string& str, vector<int>& prefix)
{
    prefix[0] = 0;
    int i = 1;
    int j = 0;
    int n = (int) str.length();
    while(i < n)
    {
        if(str[i] == str[j])
        {
            prefix[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if(j > 0)
                j = prefix[j - 1];
            else{
                prefix[i] = 0;
                i++;
            }
        }
    }

}

void func(string& str,int k, vector<int>& prefix)
{
    if(str.length() == 0)
    {
        cout << 0 << endl;
        return;
    }
    if(k == 1)
    {
        cout << str.length() << endl;
        return;
    }
    preprocess(str,prefix);
    int n = (int) str.length();
    int prefix_length = prefix[n - 1];
    int remaining_length = n - prefix_length;
    long long ans = n + 1LL * (k - 1) * remaining_length;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t > 0)
    {
        string str;
        int k;
        cin >> str;
        cin >> k;
        vector<int> prefix(str.size());
        func(str,k, prefix);
        t--;
    }
    return 0;
}