#pragma once
#include <string>
#include <vector>

typedef std::wstring text;
typedef std::vector<text> wordList;
class TextSplitter {
private:

	text _text;

	wordList _chunks;

	int _chunkSize;

public:

	TextSplitter();

	TextSplitter(text text);

	void setText(text text);

	text getText();

	wordList getChunks();

	int getChunkSize();
	
	void chunkText();

	void chunkText(int chunkSize);

};