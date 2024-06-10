#include "TextSplitter.h"
#include <sstream>
#include <locale>

TextSplitter::TextSplitter() : _chunkSize(1) {};

TextSplitter::TextSplitter(text text) : _text(text), _chunkSize(1) {};

void TextSplitter::setText(text text) {
	_text = text;
};

text TextSplitter::getText() {
	return _text;
}

wordList TextSplitter::getChunks() {
	return _chunks;
}

int TextSplitter::getChunkSize() {
	return _chunkSize;
}

void TextSplitter::chunkText() {
	_chunks.clear();
	_chunkSize = 1;
	std::wistringstream stream(_text);
	std::wstring word;


	while (stream >> word)
		_chunks.push_back(word);
}

void TextSplitter::chunkText(int chunkSize) {

	
	chunkText();
	if (chunkSize == 1)
		return;
	_chunkSize = chunkSize;
	wordList chunks;


	int count = 0;
	text temp = L"";
	for (auto& word : _chunks) {
		if (count > 0 && count < chunkSize) 
			temp += L" ";
		temp += word;
		count++;

		if (count == chunkSize) {
			chunks.push_back(temp);
			temp = L"";
			count = 0;
		}
	}

	if (count > 0)
		chunks.push_back(temp);

	_chunks = chunks;
}