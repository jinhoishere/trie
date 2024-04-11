// CS 3100 Project 5 by Jinho Nam
// There must be "Trie.h" file in the same directory

#include "Trie.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Default constructor
Trie::Trie() {
    root = new Node();
    numOfNodes = 1;
    numOfWords = 0;
}

// Copy Constructor
Trie::Trie(const Trie& copied) {
    root = nullptr;
    numOfNodes = 0;
    numOfWords = 0;

    root = new Node();
    numOfNodes += 1;
    
     // Copy from &copied to *this
    copyHelper(copied.root, root);
    // Copy # of words as well
    (this -> numOfWords) = (copied.numOfWords);
    
}

// Destructor
Trie::~Trie() {
    // return; // For memory leak test

    // If the trie is empty
    if (!root) {
        return;
    }
    // Else
    else {
        deleteHelper(root);
    }
}

// -------------------------------------------------------------
// Trie::opearator=: create a new trie that is exactly
//                       same as the parameter one.
// Returns: *this (Trie&)
// Parameters:
//       copied (const Trie&)
// -------------------------------------------------------------
Trie& Trie::operator=(const Trie& copied) {
    this -> deleteHelper(root);
    root = nullptr;
    numOfNodes = 0;
    numOfWords = 0;

    copyHelper(copied.root, root);

    return *this;
}

// -------------------------------------------------------------
// Trie::copyHelper: Help deep-copying a trie from copiedNode to newNode
// 
// Returns: -
// Parameters:
//       copiedNode (const Node*)
//       newNode (Node*&)
// -------------------------------------------------------------
void Trie::copyHelper(const Node* copiedNode, Node*& newNode) {
    // Copy node one by one recursively
    for (int i = 0; i < 26; i++) {
        if ((copiedNode -> ptrs[i]) != nullptr) {
            (newNode -> ptrs[i]) = new Node();
            numOfNodes += 1;
            (newNode -> ptrs[i] -> isEnd) = (copiedNode -> ptrs[i] -> isEnd);
            copyHelper(copiedNode -> ptrs[i], newNode -> ptrs[i]);
        }
    }
}

// -------------------------------------------------------------
// Trie::deleteHelper: Help destructor by deleting node one by one
//                       
// Returns: -
// Parameters:
//       current (Node *)
// -------------------------------------------------------------
void Trie::deleteHelper(Node* current) {
    // Delete node one by one recursively
    if (!current) {
        return;
    }
    else {
        for (int i = 0; i < 26; i++) {
            deleteHelper(current -> ptrs[i]);
        }
        numOfNodes -= 1;
        delete current;
    }
}

// -------------------------------------------------------------
// Trie::insert: Insert the given word to the trie
//                       
// Returns: true (bool) - successfully inserted it
//          false (bool) - failed to insert it
// Parameters:
//       word (string)
// -------------------------------------------------------------
bool Trie::insert(string word) {
    // Local variables
    Node* current = root;
    int index = -1; // Set default index as -1

    // Duplication check
    if (find(word)) {
        cout << "** There's already " << word << " in the trie. **" << endl;
        return false;
    }

    // Insert node one by one along with each pointer
    for (char letter : word) {
        index = letter - 'a';
        if (current -> ptrs[index] == nullptr) {
            current -> ptrs[index] = new Node();
            numOfNodes += 1; 
        }
        current = current -> ptrs[index];
    }   

    (current -> isEnd) = true;
    numOfWords += 1;

    return true;
}

// -------------------------------------------------------------
// Trie::find: Check if the given word is in the trie
//                       
// Returns: true (bool) - found the given word in the trie
//          false (bool) - the given word is not in the trie
// Parameters:
//       word (string)
// -------------------------------------------------------------
bool Trie::find(string word) {
    // Local variables
    Node* current = root;
    int index = -1;

    for (char letter : word) {
        index = letter - 'a';
        // If the trie doesn't have the letter, return false
        if ((current -> ptrs[index]) == nullptr) {
            return false;
        }
        // Move on to the next node
        current = current -> ptrs[index];
    }
    // Check if the current node is the end node
    if ((current -> isEnd) == true) {
        return true;
    }
    // Return false;
    return false;
    
}

// Return the number of words in the trie
int Trie::count() {
    return numOfWords;
}

// Return the total number of nodes in the trie
int Trie::getSize() {
    return numOfNodes;
}

// -------------------------------------------------------------
// Trie::completeCount: Return the number of words in the trie
//                      starting with the given word 
// Returns: result (int) - the number of words starting with
//                         the given word
// Parameters:
//       word (string)
// -------------------------------------------------------------
int Trie::completeCount(string word) {
    Node* current = root;
    int index = -1;
    int result = 0;

    for (char letter : word) {
        index = letter - 'a';
        if (current -> ptrs[index] == nullptr) {
            return 0;
        }
        current = current -> ptrs[index];
    }

    // count
    result = completeCounterHelper(current, result);

    return result;
}

// -------------------------------------------------------------
// Trie::completeCountHelper: Help completeCounter() by called
//                            recursively
// Returns: result (int) - the number of words
// Parameters:
//       current (Node*&)
//       counting (int &)
// -------------------------------------------------------------
int Trie::completeCounterHelper(Node*& current, int& counting) {
    int result = 0;
    for (int i = 0; i < 26; i++) {
        if ((current -> ptrs[i]) != nullptr) {
            result += completeCounterHelper(current -> ptrs[i], counting);
        }
    }

    // Check if the node is pointed by the last letter of a word
    if (current -> isEnd) {
        result += 1;
    }

    return result;
}

// -------------------------------------------------------------
// Trie::complete: Return all words in the trie starting with
//                 the given word
// Returns: wordBundle (vector<string>)
// Parameters:
//       word (string)
// -------------------------------------------------------------
vector<string> Trie::complete(string word) {
    vector<string> wordBundle;
    Node* current = root;
    int index = -1;

    for (char letter : word) {
        index = letter - 'a';
        if ((current -> ptrs[index]) == nullptr) {
            return wordBundle;
        }
        current = current -> ptrs[index];
    }

    wordBundle = completeHelper(word, current, wordBundle);
    
    return wordBundle;
    
}

// -------------------------------------------------------------
// Trie::completeHelper: Help complete() by called recursively
//                            
// Returns: bundle (vector<string>&) - wordBundle from complete()
// Parameters:
//       givenWord (string&)
//       current (Node*&)
//       bundle (vector<string>&)
// -------------------------------------------------------------
vector<string>& Trie::completeHelper(string& givenWord, Node*& current, vector<string>& bundle) {
    // Local variables
    string newWord = "";

    if ((current -> isEnd) == true) {
        bundle.push_back(givenWord);
    }

    for (int i = 0; i < 26; i++) {
        if ((current -> ptrs[i]) != nullptr) {
            newWord = givenWord + char('a'+ i);
            bundle = completeHelper(newWord, (current -> ptrs[i]), bundle);
            newWord = givenWord;
        }
    }
    return bundle;
}