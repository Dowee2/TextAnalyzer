#include "AnalyzeText.h"
#include <fstream>
#include <sstream>
#include "Utils/Helper.h"
#include "Printer/Output.h"

using namespace Utils;
namespace Models
{
	AnalyzeText::AnalyzeText(string filePath)
	{
		buildLibrary(filePath);
	}

	AnalyzeText::AnalyzeText()
	{

	}

	AnalyzeText::~AnalyzeText()
	{

	}

	void AnalyzeText::buildLibrary(string filePath)
	{
		fstream inputfile;
		inputfile.open(filePath, ios::in);
		if (inputfile.is_open())
		{
			string line;
			while (getline(inputfile, line)) {
				
				std::istringstream iss(line);
				std::string word;
				while (iss >> word) {
					word = Helper::toLower(word);
					removePunctuation(word);
					if (word != "")
					{
						addWord(word);
					}
					
				}
			}
			inputfile.close();
		}
		else
		{
			Utils::Helper::Print("Error: File not found");
		}
	}

	void AnalyzeText::addWord(const string& word)
	{
		Helper::toLower(word);
		if (this->parsedWords.count(word) > 0)
		{
			this->parsedWords[word]++;
		}
		else
		{
			this->parsedWords[word] = 1;
		}
	}

	void AnalyzeText::removeWord(string& word)
	{
		Helper::toLower(word);
		if (this->parsedWords.count(word) > 0)
		{
			this->parsedWords.erase(word);
		}
	}

	void AnalyzeText::decrementWord(string& word, string decrementby)
	{
		word = Helper::toLower(word);

		if (decrementby.find_first_not_of("0123456789") != string::npos)
		{
			throw std::invalid_argument("Value passed in for /d should be an integer. Values passed in.... word: " + word + ", integer: " + decrementby);
		}
		int value = stoi(decrementby);
		if (this->parsedWords.count(word) > 0)
		{
			this->parsedWords[word] -= value;
		}
		else {
			return;
		}

		if (this->parsedWords[word] <= 0)
		{
			this->removeWord(word);
		}		
	}

	void AnalyzeText::incrementWord(string& word, string incrementby)
	{
		word = Helper::toLower(word);	

		if (incrementby.find_first_not_of("0123456789") != string::npos)
		{
			throw std::invalid_argument("Value for /a must be an word followed by an integer. Values passed in... word: " + word + ", integer: " +incrementby);
		}
		int value = stoi(incrementby);
	
		if (this->parsedWords.count(word) > 0)
		{
			this->parsedWords[word] += value;
		}
		else
		{
			this->parsedWords[word] = value;
		}
	}

	void AnalyzeText::removePunctuation(string& text)
	{
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] < 'a' || text[i] > 'z')
			{
				text.erase(i, 1);
				i--;
			}
		}
	}

	map<string, int> AnalyzeText::getWords() const
	{
		return this->parsedWords;
	}

	map<int, vector<string>> AnalyzeText::getWordsByFrequency() const
	{
		map<int, vector<string>> wordsByFrequency;
		for (auto it = this->parsedWords.begin(); it != this->parsedWords.end(); it++)
		{
			if (wordsByFrequency.count(it->second) > 0)
			{
				wordsByFrequency[it->second].push_back(it->first);
			}
			else
			{
				wordsByFrequency[it->second] = vector<string>{it->first};
			}
		}
		return wordsByFrequency;
	}

	map<char, vector<string>> AnalyzeText::getWordsByAlphabet() const
	{
		map<char, vector<string>> wordsByAlphabet;
		for (auto it = this->parsedWords.begin(); it != this->parsedWords.end(); it++)
		{
			if (wordsByAlphabet.count(it->first[0]) > 0)
			{
				wordsByAlphabet[it->first[0]].push_back(it->first);
			}
			else
			{
				wordsByAlphabet[it->first[0]] = vector<string>{it->first};
			}
		}
		return wordsByAlphabet;	
	}



}
