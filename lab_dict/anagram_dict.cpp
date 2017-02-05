/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>
#include<sstream>
#include<iostream>

using std::string;
using std::vector;
using std::stringstream;
using std::find;
using std::sort;
using std::ifstream;
using std::cout; using std::endl;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    ifstream wordsFile(filename);
    vector<string> x;
    string word;

    if (wordsFile.is_open()) {
      while (getline(wordsFile, word)) {
          x.push_back(word);
      }

    }

    init(x);
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{

  init(words);

}

bool compare(string a, string b){
    return (a.compare(b) < 0);
}



std::string AnagramDict::getAlpha(const string& obj) const
{
  vector<string> tokens;

  for (int i = 0; i < (int)obj.size(); i++)
  {
      tokens.push_back(obj.substr(i,1));
  }

  sort(tokens.begin(), tokens.end(), compare);

  string post;

  for (auto const& d : tokens)
  {
    post += d;
  }

  return post;
}
void AnagramDict::init(const vector<string>& words)
{
  for (int i = 0; i < (int)words.size(); i++)
  {
    string obj = words[i];
    string post = getAlpha(obj);

    vector<string> &x = dict[post];

    // cout << "for the word " << obj << " the anagrams " << " are " << endl;
    // for (auto const& d : x)
    // {
    //   cout << d << " ";
    // }
    // cout << endl;

    if (find(x.begin(), x.end(), obj) != x.end())
    {
      // cout << "this will never be hit" << endl;
    }

    else
    {
      x.push_back(obj);
    }
  }

}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    vector<string> x;
    try{

          x = dict.at(getAlpha(word));
         return x;
       }

    catch(std::out_of_range e)
    {
      return vector<string> ();
    }
    return x;
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> x;
    for (auto it = dict.begin(); it != dict.end(); it++)
    {
      // cout << it->first;
      if ((it->second).size() > 1)
      {
         x.push_back(it->second);
      }
    }

    return x;
}
