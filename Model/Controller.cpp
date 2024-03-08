#include "Controller.h"
#include "../Utils/Helper.h"
#include <string>
using namespace std;
using namespace utils;

namespace models
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
		if (this->argc < 2)
		{
			Helper::Print("Not enough arguments");
			output.printUsageStatement();
			exit(1);
		}
		try
		{
			for (size_t i = 1; i < argc; i++)
			{
				string arg = this->argv[i];

				if (arg[0] != '/')
				{
					if (this->inFile == "")
					{
						this->inFile = arg;
						this->analyzeText.buildLibrary(this->inFile);
					}
					else
					{
						Settings::output_file = arg;
					}
				}
				else if (arg == "/?")
				{
					output.printUsageStatement();
				}
				else if (arg == "/a" || arg == "/d" || arg == "/da")
				{
					if (arg == "/a" || arg == "/d")
					{
						if (i + 2 >= argc)
						{
							throw std::invalid_argument(
								"Not enough arguments passed in for " + arg + " Usage is: " + arg + " <word> <count>.");
						}
						string word = this->argv[i + 1];
						string count = this->argv[i + 2];
						i += 2;
						this->deferredOperations[arg].push_back(word);
						this->deferredOperations[arg].push_back(count);
					}
					else
					{
						if (i + 1 > argc)
						{
							throw std::invalid_argument(
								"Not enough Arguments passed in for " + arg + " Usage is: " + arg + " <word>.");
						}
						string word = this->argv[i + 1];
						i += 1;
						this->deferredOperations[arg].push_back(word);
					}
				}
				else if (arg[1] == 'c')
				{
					string value = arg.substr(2);
					if (value.find_first_not_of("0123456789") != string::npos)
					{
						throw std::invalid_argument(
							"Argument passed in for /c should be an integer. I.e /c6 for column count of 6");
					}
					int column = stoi(value);
					Settings::COLUMN_COUNT = column;
				}

				else if (arg[1] == 'w')
				{
					string value = arg.substr(2);
					if (value.find_first_not_of("0123456789") != string::npos)
					{
						throw std::invalid_argument(
							"Value passed in for /w should be an integer. I.e /w10 for column width of 10");
					}
					int width = stoi(value);
					Settings::COLUMN_WIDTH = width;
				}
				else if (arg == "/o")
				{
					Settings::ISOVERWRITING = true;
				}

				else if (arg == "/sa")
				{
					Settings::ORDERING = 1;
				}
			}
			this->processDeferredOperations();
		}
		catch (const std::exception& e)
		{
			Helper::Print("Invalid arguments");
			this->output.printUsageStatement();
			this->output.printError(e.what());
			exit(1);
		}
		if (this->inFile == "")
		{
			Helper::Print("No input file specified");
			output.printUsageStatement();
			exit(1);
		}
	}

	void Controller::run()
	{
		
		if (Settings::ORDERING == 0)
		{
			this->output.displayWordsByFrequency(analyzeText.getWordsByFrequency());
		}
		else
		{
			this->output.displayWordsByAlphabet(analyzeText.getWordsByAlphabet());
		}


		if (Settings::output_file != "")
		{
			Helper::saveToFile(output.getOutput());
		}
	}

	void Controller::processDeferredOperations()
	{
		for (auto operation : this->deferredOperations)
		{
			if (operation.first == "/a")
			{
				this->analyzeText.incrementWord(operation.second[0], operation.second[1]);
			}

			if (operation.first == "/d")
			{
				this->analyzeText.decrementWord(operation.second[0], operation.second[1]);
			}

			if (operation.first == "/da")
			{
				this->analyzeText.removeWord(operation.second[0]);
			}
		}
	}
}
