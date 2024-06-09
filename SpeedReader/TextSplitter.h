#pragma once
#include <string>
#include <vector>

typedef std::vector<std::wstring> wordList;
typedef std::vector<wordList> wordGroups;
class TextSplitter {
private:

	std::wstring _text;

	wordList _words;

public:

	TextSplitter(std::wstring text);

	wordList getWords();

	wordGroups splitText(int chunkSize);


};