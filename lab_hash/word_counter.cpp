/**
 * @file word_counter.cpp
 * Implementation of the WordFreq class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Spring 2012
 */

using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

template <template <class K, class V> class Dict>
WordFreq<Dict>::WordFreq(const string& infile)
    : filename(infile)
{
    /* nothing */
}

template <template <class K, class V> class Dict>
vector<pair<string, int>> WordFreq<Dict>::getWords(int threshold) const
{
    TextFile infile(filename);
    vector<pair<string, int>> ret;
    Dict <string, int> ourMap(17);
    /**
     * @todo Implement this function.
     * @see char_counter.cpp if you're having trouble.
     */

     while(infile.good())
     {
       std::string word = infile.getNextWord();
       if (ourMap.keyExists(word))
       {
         int times = ourMap.find(word);
         ourMap.remove(word);
         ourMap.insert(word, times + 1);
       }
       else
       {
         ourMap.insert(word, 1);
       }
     }

     TextFile anotherfile(filename);
     while(anotherfile.good())
     {
       std::string word = anotherfile.getNextWord();
       int times = ourMap.find(word);
       if (times >= threshold)
       {
         ret.push_back(pair<string, int>(word,times));
         ourMap.remove(word);
       }
     }

    return ret;
}
