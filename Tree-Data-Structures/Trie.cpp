#include <bits/stdc++.h>
using namespace std;

const int ALPHABET = 26;

struct TrieNode {
    TrieNode *children[ALPHABET];
    char val;
    bool leaf;
    size_t size;
};

TrieNode* getNode() {
    TrieNode *parent = new TrieNode;
    parent->leaf = false;
    parent->size = 0;
    for(int i = 0; i < ALPHABET; i++) {
        parent->children[i] = NULL;
    }
    return parent;
}

TrieNode* insert(TrieNode* root, string pattern) {
    TrieNode *temp = root;
    for(char i : pattern) {
        int number = i - 'a';
        if(temp->children[number] == NULL) {
            temp->children[number] = getNode();
            temp->size++;
        }
        temp = temp->children[number];
    }
    temp->leaf = true;
    return root;
}

int searchforWord(TrieNode* root, string word) {
    TrieNode *temp = root;
    int i;
    cout << root->size << endl;
    for(i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if(temp->size > 1 || temp->children[index]->size > 1) break;
        temp = temp->children[index];
    }
    return i;
}

int main(int argc, char *argv[]) {
    TrieNode *root = getNode();
    vector<string> test = {"cir", "car"};
    string minString = test.at(0);
    for(auto i : test) {
        if(i.size() < minString.size()) minString = i;
        root = insert(root, i);
    }
    int index = searchforWord(root, minString);
    cout << minString.substr(0,index+1) << endl;
    return 0;
}







