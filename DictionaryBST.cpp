#include "util.h"
#include "DictionaryBST.h"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
  //qstd::cout << word << std::endl;
  return(dictionary.insert(word).second);
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  if( dictionary.find(word) != dictionary.end() )
    return 1;
  else
    return 0;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
