#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

namespace Models
{
	class AnalyzeText
	{
	public:
		AnalyzeText(string filePath);
		AnalyzeText();
		~AnalyzeText();

		map<string, int> getWords() const;

		/**
		 * Adds specified word to the collection
		 *
		 * @postcondition collection.contains(word) == true && collection.size == collection.size + 1
		 *
		 * \param word The word to be added to the collection
		 */
		void addWord(const string& word);

		/**
		* Removes specified word from the collection
		*
		* @postcondition collection.contains(word) == false && collection.size == collection.size - 1
		*
		* \param word The word to be removed from the collection
				*/
		void removeWord(string& word);

		/**
		* Decrements the count of the specified word by the specified amount
		*
		* @postcondition collection.get(word) == collection.get(word) - decrementby
		*
		*/
		void decrementWord( string& word, string decrementby);

		/*
		* Increments the count of the specified word by the specified amount
		*
		* @postcondition collection.get(word) == collection.get(word) + incrementby
		*/
		void incrementWord(string& word, string incrementby);

		/**
		* Returns a collection of words grouped by frequency of the word
		* 
		*/
		map<int, vector<string>> getWordsByFrequency() const;
		/**
		* Returns a collection of words grouped by starting letter of the word
		*
		*/
		map<char, vector<string>> getWordsByAlphabet() const;

		/**
		* Builds a collection of words and their frequency from the specified file
		* 
		*/
		void buildLibrary(string filePath);

	private:
		map<string, int> parsedWords;
		void removePunctuation(string& text);
		
	};
	
}


