#pragma once

#include <iostream>
using namespace std;

namespace utils
{
	class Helper
	{
	public:
		static void Print(const string& text);

		/*
		* Converts a string to lowercase
		*/
		static string toLower(const string& text);


		/*
		* Saves a string to a file specified in the settings. If the file exists, and the user hasn't already specified overwriting, the user will be prompted to overwrite it unless. 
		* 
		* @param text The text to save to the file.
		*/
		static void saveToFile(string text);
	};
}
