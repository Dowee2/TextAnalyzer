#pragma once

#include <iostream>
using namespace std;
namespace Utils
{
	class Settings
	{
	public:

		Settings();

		/**
		* @brief Column count for the output file.
		*/
		static int COLUMN_COUNT;

		/**
		* @brief Column width for the output file.
		*/
		static int COLUMN_WIDTH;

		/**
		 * @brief Flag to determine if the output file should be overwritten.
		 * If true, the output file will be overwritten without prompting the user.
		 * If false, the user will be prompted if the output file already exists.
		 */
		static bool ISOVERWRITING;

		/**
		*@brief Flag to determine the sorting order of the output.
		* 0 =  Frequency
		* 1 = Alphabetically
		*/
		static int ORDERING;

		static string OUTPUT_FILE;


	};
}

