// CS 3100 Project 5 by Jinho Nam
// There must be "Trie.cpp" file in the same directory

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Trie {
    private:
        class Node {
            public: 
                // Fields for Node
                Node* ptrs[26];
                bool isEnd; // $

                // Default Constructor
                Node() {
                    for (int i = 0; i < 26; i++) {
                        ptrs[i] = nullptr;
                    };
                    isEnd = false;
                }
        };

        // Private fields for Trie
        Node* root;
        int numOfNodes; // # of nodes in the trie
        int numOfWords; // # of words in the trie

        // copyConstructor helper
        void copyHelper(const Node*, Node*&);

        // destructor helper
        void deleteHelper(Node*);

        // completeCounter() Helper
        int completeCounterHelper(Node*&, int&);

        // complete() Helper
        vector<string>& completeHelper(string&, Node*&, vector<string>&);

    public:
        // Default constructor
        Trie();

        // Copy Constructor
        Trie(const Trie&);

        // Destructor
        ~Trie();

        // Deep copy
        Trie& operator=(const Trie&);

        // Insert a new word into the trie
        bool insert(string);

        // Find the given word in the trie
        bool find(string);

        // Return # of words in the trie
        int count();

        // Return # of nodes in the trie
        int getSize();

        // Return # of words in the dictionary
        // that begin with the given input string
        int completeCount(string);

        // Return vector string containing all words
        // in the dictionary that begin with the given string
        vector<string> complete(string);

};