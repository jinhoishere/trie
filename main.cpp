// CS 3100 Project 5 by Jinho Nam
// There must be "Trie.h", "Trie.cpp", and "wordlist_linux.txt" files in the same directory

#include "Trie.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <ios>

using namespace std;

void loadFile(string& fileName, vector<string>& wordList);
void insertWordListToTrie(vector<string>& wordList, Trie& trie);
void execute(Trie& trie);
// void memoryLeakTest(); // a method to test memory leak

// main()
int main() {
    // Variables in main()
    string fileName = "";
    vector<string> wordList;

    // --------------------------------------------
    // Load file
    fileName = "./wordlist_linux.txt"; // Edit this variable based on your OS type
    // --------------------------------------------

    // --------------------------------------------
    // Load the file and extract a word list from it
    loadFile(fileName, wordList);
    // --------------------------------------------

    // --------------------------------------------
    // Create a trie
    Trie myTrie;
    // Trie myTrie2(myTrie);
    // Trie myTrie3 = myTrie;
    // --------------------------------------------
    
    // --------------------------------------------
    // Insert the word list to the trie
    insertWordListToTrie(wordList, myTrie);
    // myTrie.count(); // Return # of words in the trie
    // myTrie.getSize(); // Return # of nodes in the trie
    // --------------------------------------------

    // --------------------------------------------
    // Run the program with the trie
    execute(myTrie);
    // --------------------------------------------

    
    // --------------------------------------------
    // Memory leak test for Linux
    // --------------------------------------------
    // cout << "Pre-memory leak test..." << endl;
    // string response;
    // cin >> response;

    // int c;
    // c = getchar();
    // cin.get();

    // for (int i = 0; i < 1000; i++) {
    //     memoryLeakTest();
    // }

    // c = getchar();
    // cin.get();
    // cout << c;

    // cout << "Post-memory leak test.." << endl;
    // cin >> response;
    // --------------------------------------------
    // --------------------------------------------
    
    return 0; // End of the main()
}

// -------------------------------------------------------------
// loadFile: load a file named "fileName" and create a wordList
//           by going through a line by line in the file
// Returns: -
// Parameters:
//       fileName (string&)
//       wordList (vector<string>&)
// -------------------------------------------------------------
void loadFile(string& fileName, vector<string>& wordList) {
    ifstream inputFile(fileName);
    string line;

    if (inputFile) {
        while (getline(inputFile, line)) {
            wordList.push_back(line);
            // cout << line << endl;
        }
    }
    else {
        cout << "*** File doesn't exist. Check the file path. ***" << endl;
        exit(0);
    }
    
    inputFile.close();
}

// -------------------------------------------------------------
// insertWordListToTrie: insert the extracted wordList to the trie
// 
// Returns: -
// Parameters:
//       wordList (vector<string>&)
//       trie (Trie&)
// -------------------------------------------------------------
void insertWordListToTrie(vector<string>&wordList, Trie& trie) {
    for (string word : wordList) {
        trie.insert(word);
    }
}

// -------------------------------------------------------------
// execute: Run the program with the given trie
// 
// Returns: -
// Parameters:
//       trie (Trie&)
// -------------------------------------------------------------
// Run the program with the trie
void execute(Trie& trie) {
    string userInput;
    string search;

    while (true) {
        cout << "Please enter a word prefix (or press enter to exit): ";
        getline(cin, userInput);
        if (userInput.empty()) {
            break;
        }
        else {
            search = userInput;
            cout << "There are " << trie.complete(search).size() 
            << " completions for the prefix \'" << search << "\'.  ";

            cout << "Show completions? ";
            cin >> userInput;
            cout << endl;

            // If the userInput is "Yes" or "yes"
            if ((userInput == "Yes") || (userInput == "yes")) {
                cout << "Completions" << endl;
                cout << "-----------" << endl;
                for (string word : trie.complete(search)) {
                    cout << word << endl;
                }
                cout << endl;
            }
            // Else the userInput is other than "yes"
            else {
                // Clear the input buffer for the "enter" input
                cin.ignore(numeric_limits<streamsize>::max(),'\n');  
                continue;
            }
        }

        // Clear the input buffer for the "enter" input
        cin.ignore(numeric_limits<streamsize>::max(),'\n');  
    }
}

// void memoryLeakTest() {
//     Trie testTrie;

//     testTrie.insert("alsuhnvrg");
//     testTrie.insert("tjsnxsng");
//     testTrie.insert("ajhaue");
//     testTrie.insert("taldshfo");
//     testTrie.insert("cwuehlna");
//     testTrie.insert("cwuehlnd");
//     testTrie.insert("zoiglag");

//     for (int i = 0; i < 1000; i++) {
//         Trie newTrie = testTrie;
//     }
// }