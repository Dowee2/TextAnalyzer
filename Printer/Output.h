#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace View
{
	class Output
	{
	public:
		Output();
		~Output();

		/*
		* Prints the usage statement to the console
		*/
		void printUsageStatement();

		/*
		* Prints an error message to the console
		* @param string error
		*/
		void printError(const string& error);
		bool static promptOverwite();


		/*
		* Returns the output string
		* 
		* @return string output
		* 
		*/
		string getOutput() const;

		/*
		* Displays words which are grouped by their frequency. The most frequent words are displayed first.
		* @param map<char, vector<string>> words The collection of words to be displayed
		*/
		void displayWordsByFrequency(const map<int, vector<string>>& words);
		/*
		* Displays words alongside their frequency grouped alphabetically by their starting letter.
		* @param map<char, vector<string>> words The collection of words to be displayed
		*/
		void displayWordsByAlphabet(const map<char, vector<string>>& words);

	private:
		string output;
	};
}
