#pragma once
#include <string>
#include <vector>

typedef std::vector<std::string> wordList;
typedef std::vector<wordList> wordGroups;
class TextSplitter {
private:

	std::string _text;

	wordList _words;

public:

	TextSplitter(std::string text);

	wordList getWords();

	wordGroups splitText(int chunkSize);


};