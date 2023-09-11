/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <vector>
#include <string>
#include <array>

//template<typename Data>

class Node
{
  public:
  //Node* children[27] = {0};
  // Node *children[27];//works on mac machine only
  //Node *children = new Node[27];//doesnt seem to work
  //std::vector <Node *> children(5); //doesnt seem to work
  //std::vector <Node*> children(27); //causes seg fault on mac
  std::vector <Node*> children{27}; //seems to work
  //std::array< Node*, 27> Chil;
  int freq = 0;

    Node();	 
};



/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{
 public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return the node if word is in the dictionary, and nulptr otherwise */
  Node* findPrefix(std::string word) const;

  /* Return true if word is in the dictionary, and false otherwise */
  void print();
  
  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
    predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();

private:
  //A root node
  Node* root;
  // needs to contain: pointer to next array and freq (freq of 0 means no word)
  // the letter name information is contained by array index

  // Add your own data members and methods here
};

#endif // DICTIONARY_TRIE_H
