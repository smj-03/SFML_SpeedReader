#include "TextSplitter.h"
#include <sstream>

TextSplitter::TextSplitter(std::string text) : _text(text) {
	std::istringstream stream(text);
	std::string word;

	while (stream >> word)
		_words.push_back(word);

}

wordList TextSplitter::getWords() {
	return _words;
}

wordGroups TextSplitter::splitText(int chunkSize) {
	wordGroups wordGroups;

	int count = 0;
	wordList group;
	for (auto& word : _words) {
		group.push_back(word);
		count++;

		if (!(count % chunkSize)) {
			wordGroups.push_back(group);
			group.clear();
		}
	}
	wordGroups.push_back(group);

	return wordGroups;
}