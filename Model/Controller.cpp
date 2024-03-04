#include "Controller.h"
#include "../Utils/Helper.h"
#include <string>
using namespace std;
using namespace Utils;

namespace Models
{
	Controller::Controller(int argc, char* argv[])
	{
		this->argc = argc;
		this->argv = argv;
		this->inFile = "";
		this->handleArguments();
		this->run();
	}

	Controller::~Controller()
	{
	}

	void Controller::handleArguments()
	{
		if (this->argc < 2) {
			Helper::Print("Not enough arguments");
			output.printUsageStatement();
			exit(1);
		}

		for (size_t i = 1; i < argc; i++)
		{
			string arg = this->argv[i];

			if (arg[0] != '/') {
				if (this->inFile == "")
				{
					this->inFile = arg;
				} else
				{
					Settings::OUTPUT_FILE = arg;
				}
			}
			else if (arg == "/?") {
				output.printUsageStatement();
			}
			else if (arg == "/a" ) {
				string word = this->argv[i + 1];
				string count = this->argv[i + 2];
				i = i + 2;
				analyzeText.incrementWord(word, count);
			}
			else if (arg[1] == 'c') 
			{
				int column = arg[2] - '0';
				Settings::COLUMN_COUNT = column;
			}

			else if (arg[1] == 'w')
			{
				int width = arg[2] - '0';
				Settings::COLUMN_WIDTH = width;
			}

			else if (arg == "/d") 
			{
				string word = this->argv[i + 1];
				string count = this->argv[i + 2];
				i = i + 2;
				
				analyzeText.decrementWord(word, count);
			}

			else if (arg == "/da") 
			{
				string word = this->argv[i + 1];
				analyzeText.removeWord(word);
			}

			else if (arg == "/0") 
			{
				Settings::OVERWRITE = true;
			}
			
			else if (arg == "/sa")
			{
				Settings::ORDERING = 1;
			}
	
		}
		analyzeText = AnalyzeText(this->inFile);
	}

	void Controller::run()
	{
		if (Settings::ORDERING == 0)
		{
			output.displayWordsByFrequency(analyzeText.getWordsByFrequency());
		}
		else
		{
			output.displayWordsByAlphabet(analyzeText.getWordsByAlphabet());
		}

		if (Settings::OUTPUT_FILE != "")
		{
			Helper::saveToFile(output.getOutput());
		}
	}
}	