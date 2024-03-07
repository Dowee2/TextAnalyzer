#pragma once
#include <iostream>
#include "../Printer/Output.h"
#include "../AnalyzeText.h"
#include "../Utils/Settings.h"
#include <vector>

using namespace View;
namespace Models
{
	class Controller
	{
	private:
	int argc;
	char** argv;
	string inFile;
	string outFile;
	map<string, vector<string>> deferredOperations;

	Utils::Settings settings;
	Output output;
	AnalyzeText analyzeText;

	void handleArguments();
	void run();
	void processDeferredOperations();

	public:
		Controller(int argc, char* argv[]);
		~Controller();
	};


}


