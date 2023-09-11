#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  return( dictionary.insert(word).second );
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  if( dictionary.find(word) != dictionary.end() )
    return 1;
  else
    return 2;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
