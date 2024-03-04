#pragma once

#include <iostream>
using namespace std;
namespace Utils
{
	class Helper
	{
	public:
		static void Print(const string& text);

		static string toLower(string text);

		static void saveToFile(string text);
	};
}


