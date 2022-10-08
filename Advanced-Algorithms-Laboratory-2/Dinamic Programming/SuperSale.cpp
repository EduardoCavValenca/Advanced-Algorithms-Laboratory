//Tentando usar tecnicas avancadas

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

using products_info = vector<pair< uint_fast16_t, uint_fast16_t>>;

void fill_knapsack_table(vector<vector<uint_fast64_t>> &Knapsack_table,
                         const products_info &products, const uint_fast16_t &max_weight){

    for(size_t i = 0; i <= products.size(); i++)
    {
        for(uint_fast16_t w = 0; w <= max_weight; w++)
        {
            if (i == 0 || w == 0)
                Knapsack_table[i][w] = 0;
            else if (products[i - 1].second <= w)
                Knapsack_table[i][w] = max(products[i - 1].first +
                                           Knapsack_table[i - 1][w - products[i - 1].second],
                                           Knapsack_table[i - 1][w]);
            else
                Knapsack_table[i][w] = Knapsack_table[i - 1][w];
        }
    }
}

int main() {

    uint_fast16_t T;
    size_t N, G;

    uint_fast64_t total;
    uint_fast16_t max_weight;

    cin >> T;
    while(T--){

        cin >> N;
        products_info products(N);
        for (auto& [p_price, p_weight] : products)
            cin >> p_price >> p_weight;

        cin >> G;
        vector<uint_fast16_t> weights(G);
        for (auto& weight : weights)
            cin >> weight;

        max_weight = *max_element(weights.begin(), weights.end());
        vector<vector<uint_fast64_t>> Knapsack_table(N + 1, vector<uint_fast64_t>(max_weight + 1));
        fill_knapsack_table(Knapsack_table, products, max_weight);

        total = 0;
        for (const auto& weight : weights)
            total += Knapsack_table[N][weight];

        cout << total << endl;
    }
    return 0;
}
