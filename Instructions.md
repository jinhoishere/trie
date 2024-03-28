## Table of Contents:
* [Learning Objectives](#learning-objectives)
* [Overview](#overview)
* [The Trie Class](#the-trie-class)
* [Main program using the trie](#main-program-using-the-trie)
* [Grading](#turn-in-and-grading)

---

## _Learning Objectives_

- Demonstrate effective use of memory management techniques in C++
- Implement a data structure to meet given specifications
- Design, implement, and use a trie data structure
- Analyze operations for time complexity

## _Overview_

Your task for this assignment is to implement an alphabet trie data structure, and to use this data structure to write an autocomplete program using an English dictionary.
 
## _The Trie Class_

In order to implement your autocomplete program, you will need to create a trie data structure (class Trie) to facilitate efficient word searches from an English dictionary.

  - `bool Trie::insert(string)` – Insert a new word into the trie. Duplicate words are not allowed. This function should return **true** if the word is successfully inserted into the trie, and **false** if the word could not be inserted (for example, due to a duplicate word already found in the trie).

  - `int Trie::count()` – return the number of **words** in the trie

  - `int Trie::getSize()` – return the total number of **nodes** in the trie

  - `bool Trie::find(string)` – if the given word is found in the trie, this function should return **true**, otherwise this function should return **false**

  - `int Trie::completeCount(string)` – this function should return the number of words in the dictionary that begin with the given input string. If no matching words are found, the function should return zero.

  - `vector<string> Trie::complete(string)` – this function should return a C++ vector of strings containing all of the words in the dictionary that begin with the given input string. For each word found in the trie, there will be one value in the vector. If no matching words are found, the function should return an empty vector.

**Example:** The call `resultVector = myTrie.complete("addr")` were called on a trie built with the wordlist.txt file provided with this project should return a vector containing the strings: {"address", "addressable", "addressed", "addressee", "addressees", "addresses", "addressing"}.

`Trie& Trie::operator=(const Trie&)` – trie1 = trie2 should remove all contents of trie1 (without memory leaks) and make an independent copy of trie2 in trie1.

`Copy constructor` – must correctly make an independent trie that is an exact copy of the original trie.


## _Main program using the trie_

You should test your trie with a main() function that loads the provided English dictionary file, prompts the user for a prefix, and then uses the trie to find all completions for the prefix. An example of the execution of your main program follows:

```
Please enter a word prefix (or press enter to exit):  addr
There are 7 completions for the prefix 'addr'.  Show completions?  Yes
Completions
-----------
address
addressable
addressed
addressee
addressees
addresses
addressing

Please enter a word prefix (or press enter to exit):
```

## _Turn in and Grading_

See [README.md](https://github.com/WSU-CS-3100/Project4/blob/main/README.md)
