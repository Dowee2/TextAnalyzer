#pragma once
#include <iostream>
#include "../Printer/Output.h"
#include "../AnalyzeText.h"
#include "../Utils/Settings.h"

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

	Utils::Settings settings;
	Output output;
	AnalyzeText analyzeText;

	void handleArguments();
	void run();

	public:
		Controller(int argc, char* argv[]);
		~Controller();
	};


}


