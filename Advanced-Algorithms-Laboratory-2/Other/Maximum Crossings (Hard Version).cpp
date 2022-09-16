#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

int main() {

    int test_cases;

    cin >> test_cases;

    while(test_cases--){

        int n;
        cin >> n;
        vector<int> wires(n);

        for(auto i = 0; i < n; i++)
            cin >> wires[i];

        long long result = 0;
        ordered_set<pair<int, int>> previous;

        for(int i = 0; i < n; i++){
            int no_crosses = previous.order_of_key({wires[i], -1});
            result += previous.size() - no_crosses;
            previous.insert({wires[i], i});
        }

        cout << result << endl;

    }

}