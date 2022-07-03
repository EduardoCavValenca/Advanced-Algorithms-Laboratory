#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node
{
    public:
    int counter;
    unordered_map <int, node> *next;

    node()
    {
        next = nullptr;
        counter = 0;
    }

};

node trie;

void add_to_trie(string& word){

    node *current;
    current = &trie;

    for (auto const& c: word){
        int ch = c - 'a';

        if (current->next == nullptr){
            current->next = new unordered_map <int, node>;
        }

        current->next->insert(make_pair(ch, *new node));

        current = &current->next->at(ch);

        current->counter++;

    }

}

void erase_of_trie(string& word) {

    node *current;
    current = &trie;

    for (auto i = 0; i < (int) word.size(); i++){
        int ch = word[i] - 'a';

        if (current->next == nullptr){
            return;
        }

        try{
            current = &current->next->at(ch);
        }
        catch (...) {
            return;
        }

        current->counter--;

    }

}

int find_prefix(string& prefix){

    node *current;
    current = &trie;

    for (auto i = 0; i < (int) prefix.size(); i++){
        int ch = prefix[i] - 'a';

        if (current->next == nullptr){
            return 0;
        }

        try{
            current = &current->next->at(ch);
        }
        catch (...) {
            return 0;
        }

        if (i == (int) prefix.size() - 1)
            return current->counter;

    }

    return 0;
}




int main()
{
    int queries_n;
    cin >> queries_n;

    string read;

    int operation;

    for (auto i = 0; i < queries_n; i++) {
        cin >> operation >> read;
        if (operation == 1)
            add_to_trie(read);
        else if (operation == 2)
            erase_of_trie(read);
        else if (operation == 3)
            cout << find_prefix(read) << endl;
    }

    return 0;
}