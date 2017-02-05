/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<StringTriple> cartalk_puzzle(PronounceDict d, const string& word_list_fname)
{
vector<StringTriple> triples;
ifstream wordsFile(word_list_fname);
string word;
if (wordsFile.is_open()) {
  /* Reads a line from `wordsFile` into `word` until the file ends. */

  while (getline(wordsFile, word)) {
      string first = word.substr(0,1) + word.substr(2);
      string second = word.substr(1);

      if (d.homophones(first, second) && d.homophones(word,first) && d.homophones(first,second))
      {
        StringTriple x;
        get<0>(x) = first;
        get<1>(x) = second;
        get<2>(x) = word;
        triples.push_back(x);
      }
  }
}
    return triples;
}
