#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

namespace models
{
	class AnalyzeText
	{
	public:
		AnalyzeText(const string& filePath);
		AnalyzeText();
		~AnalyzeText();

		map<string, int> getWords() const;

		/**
		 * Adds specified word to the collection
		 *
		 * @postcondition collection.contains(word) == true && collection.size == collection.size + 1
		 *
		 * @param word The word to be added to the collection
		 * 
		 */
		void addWord(const string& word);

		/**
		* Removes specified word from the collection
		*
		* @postcondition collection.contains(word) == false && collection.size == collection.size - 1
		*
		* @param word The word to be removed from the collection
				*/
		void removeWord(string& word);

		/**
		* Decrements the count of the specified word by the specified amount
		* 
		* @precondition decrementby == int
		* @postcondition collection.get(word) == collection.get(word) - decrementby
		* 
		* @param word The word to be decremented
		* @param decrementby The amount to decrement the word by
		*
		*/
		void decrementWord(string& word, string decrementby);

		/*
		* Increments the count of the specified word by the specified amount
		* 
		* @precondition incrementby == int
		* @postcondition collection.get(word) == collection.get(word) + incrementby
		* 
		* @param word The word to be incremented
		* @param incrementby The amount to increment the word by
		*
		*/
		void incrementWord(string& word, string incrementby);

		/**
		* Returns a collection of words grouped by frequency of the word
		* 
		* @return map<int, vector<string>> words  Grouped by frequency
		*/
		map<int, vector<string>> getWordsByFrequency() const;

		/**
		* Returns a collection of words grouped by starting letter of the word
		*
		* 
		* @return map<char, vector<string>> words  Grouped by starting letter
		*/
		map<char, vector<string>> getWordsByAlphabet() const;

		/**
		* Builds a collection of words and their frequency from the specified file
		* 
		* @param filePath The path to the file to be parsed
		* 
		* @postcondition collection.size == collection.size + unique words in file not already in collection
		*/
		void buildLibrary(string filePath);

	private:
		map<string, int> parsedWords;
		void removePunctuation(string& text);
	};
}
