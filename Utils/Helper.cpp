#include "Helper.h"
#include "../Utils/Settings.h"
#include "../Printer/Output.h"

#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

namespace utils
{
	void Helper::Print(const string& text)
	{
		std::cout << text << std::endl;
	}

	string Helper::toLower(const string& text)
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
		string filename = Settings::output_file;

		if (fs::exists(filename) && !Settings::ISOVERWRITING)
		{
			if (View::Output::promptOverwite())
			{
				ofstream file(filename, std::ios::out);
				file.open(filename, ios::out);
				file << text;
				file.close();
			}
		}
		else
		{
			std::ofstream file(filename, std::ios::out);
			file.open(filename, ios::out);
			file << text;
			file.close();
		}
	}
}
