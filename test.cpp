#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{
  std::cout << "testing..." << std::endl;

  //Initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;

  //words.push_back("harry");
  words.push_back("basketball");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");
  
  
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      //cout << *wit << endl;
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

   cout << endl << "Finding elements that were just inserted into Dictionaries..." << endl;

  //*
  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Finding: \"" << *wit << "\"... ";
      t_bst = d_bst.find(*wit);
      t_ht = d_ht.find(*wit);
      tt = dt.find(*wit);
      if(!t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(!t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(!tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(t_bst && t_ht && tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
      }//*/

   cout << endl << "Finding elements that were not inserted into Dictionaries..." << endl;

  //*

   cout << "Finding: \"" << "basket" << "\"... ";
   t_bst = d_bst.find("basket");
   t_ht = d_ht.find("basket");
   tt = dt.find("basket");
   if(t_bst)
     {
       cout << "failed for DictionaryBST... ";
     }
   if(t_ht)
     {
       cout << "failed for DictionaryHashset... ";
     }
   if(tt)
     {
       cout << "failed for DictionaryTrie... ";
     }
   if(!t_bst && !t_ht && !tt)
     {
       cout << "PASSED! :D ";
     }
      cout << endl; 
      //*/

   cout << "Finding: \"" << "balrog" << "\"... ";
   tt = dt.find("balrog");
   if(tt){
     cout << "failed for DictionaryTrie... ";
   }else{
     cout << "PASSED! :D ";
   }

   cout << "Finding: \"" << "basketballs" << "\"... ";
   tt = dt.find("basketballs");
   if(tt){
     cout << "failed for DictionaryTrie... ";
   }else{
     cout << "PASSED! :D ";
   }

      cout << "Finding: \"" << "basketballss" << "\"... ";
   tt = dt.find("basketballss");
   if(tt){
     cout << "failed for DictionaryTrie... ";
   }else{
     cout << "PASSED! :D ";
   }
   
      cout << endl; 
      //*/
  
  cout << endl;

  dt.print();  
/*You are supposed to add more test cases in this file */
  
  vector<std::string> newWords = dt.predictCompletions("basketball",10);
  std::cout<< "got newWords"<< std::endl;
  vector<string>::iterator nwit;
  vector<string>::iterator nwen;
  
  nwit = newWords.begin();
  nwen = newWords.end();
  for(; nwit != nwen; ++nwit) {
    std::cout << "Got: \"" << *nwit << "\"... ";
  }

  newWords = dt.predictCompletions("c",2);
  std::cout<< "got newWords"<< std::endl;
  nwit = newWords.begin();
  nwen = newWords.end();
  for(; nwit != nwen; ++nwit) {
    std::cout << "Got: \"" << *nwit << "\"... ";
  }
  
  //vector<std::string> newWords2 = dt.predictCompletions("c",2);
  //vector<string>::iterator nwb;
  //vector<string>::iterator nwe;
  //nwb = newWords2.begin();
  //nwe = newWords2.end();
  
  return 0;
}
