#pragma once
#include <iostream>
#include "../Printer/Output.h"
#include "../AnalyzeText.h"
#include "../Utils/Settings.h"
#include <vector>

using namespace View;

namespace models
{
	class Controller
	{
	private:
		int argc;
		char** argv;
		string inFile;
		string outFile;
		map<string, vector<string>> deferredOperations;

		utils::Settings settings;
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
