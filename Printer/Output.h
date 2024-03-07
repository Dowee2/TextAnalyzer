#pragma once

#include <iostream>
#include "../Utils/Settings.h"
#include "../Utils/Helper.h"
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

		void printUsageStatement();
		void printError(string error);
		bool static promptOverwite();

		string getOutput() const;

		void displayWordsByFrequency(const map<int, vector<string>>& words);
		void displayWordsByAlphabet(const map<char, vector<string>>& words);

	private:
		string output;

	};
}


