#include "Helper.h"
#include "../Utils/Settings.h"
#include "../Printer/Output.h"	

#include <fstream>

using namespace std;
namespace Utils
{
	void Helper::Print(const string& text)
	{
		std::cout << text << std::endl;
	}

	string Helper::toLower(string text)
	{
		string output = text;
		for (size_t i = 0; i < text.length(); i++)
		{
			output[i] = tolower(output[i]);
		}
		return output;
	}

	void Helper::saveToFile(string text)
	{
		fstream file;
		string filename = Settings::OUTPUT_FILE;
		if (file.is_open())
		{
			if (View::Output::promptOverwite(filename)) {
				file.open(filename, ios::out);
				file << text;
				file.close();
			}
		}
		else
		{
			file.open(filename, ios::out);
			file << text;
			file.close();
		}
	}
}