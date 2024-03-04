#include "Output.h"
#include <iomanip>
#include <sstream>
using namespace Utils;
namespace View
{
	Output::Output()
	{
	}

	Output::~Output()
	{
	}

	void Output::printUsageStatement()
	{
        cout << "usage: TextAnalyzer infile [outfile] [options]" << endl 
            << "by Anton  Maynard" << endl
            << "Analyzes and outputs the number of words in the infile." << endl
            << "infile      The input file to analyze the words." << endl
            << "outfile     The output file to write the output to." << endl
            << "options:" << endl
            << "   /?              Displays this usage statement." << endl
            << "   /a <word count> Add the specified count of the word to the output.  E.g., -a apple 3 would add three occurrences of apple." << endl
            << "   /c<number>      Changes the number of output columns to the number specified.The default number of columns is 4." << endl
            << "   /d<word count>  Deletes the specified count of the word from the output.  E.g., -a apple 3 would delete 3 occurrences of apple." << endl
            << "   /da <word>      Delete the specified word completely from the output.E.g., -da banana would eliminate banana from the output." << endl
            << "   /o              Automatically overwrites the outfile without prompting, if the outfile already exists. If this option is not specified and the outfile exists the user will be prompted on whether to overwrite the outfile." << endl
            << "   /sa             Displays the output in alphabetic order instead of by frequency which is the default output format." << endl
            << "   /w<number>      Changes the column width for the output columns.The default column width is 18." << endl;
	}

    void Output::printError(const string& error)
    {
		cout << "Error: " << error << endl;
	}

    bool Output::promptOverwite(string filename)
    {
        cout << "The file " + filename + " already exists. Do you want to overwrite it? (y/n)" << endl;
        string response;
        cin >> response;
        if (response == "y")
        {
			return true;
		}
        return false;
    }

    string Output::getOutput() const
    {
        return this->output;
    }
    
    void Output::displayWordsByFrequency(const map<int, vector<string>>& words)
    {
        int columnCount = 0;
        ostringstream stream;

        for (auto frequency : words)
        {
            stream << "Words with frequency " << frequency.first << " : " << endl;
            for (auto word : frequency.second)
            {
				stream << left << setw(Settings::COLUMN_WIDTH) << word;
				columnCount++;
                if (columnCount == Settings::COLUMN_COUNT)
                {
                    stream << endl;
					columnCount = 0;
				}
			}
        }
        cout << stream.str();
        output = stream.str();
	}

    void Output::displayWordsByAlphabet(const map<char, vector<string>>& words)
    {
        int columnCount = 0;
        ostringstream stream;
        for (auto letter : words)
        {
			stream << "Words starting with " << letter.first << " : " <<endl;
            for (auto word : letter.second)
            {
                stream << left << setw(Settings::COLUMN_WIDTH) << word;
                columnCount++;
                if (columnCount == Settings::COLUMN_COUNT)
                {
                    stream << endl;
					columnCount = 0;
				}
			}
			cout << endl;
		}
        cout << stream.str();
        output = stream.str();
	}


}