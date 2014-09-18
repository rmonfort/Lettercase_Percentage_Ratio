#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::fixed;

// Data structure to hold ratios
struct ratio
{
	double lc;
	double uc;
};

// Calculates the ratio based on the number of occurrences and the size of the input
double set_ratio(const int& n, const double& size)
{
	return n / size;
}

// Converts ratio to a percentage
double calc_percent_ratio(const double& ratio)
{
	return ratio * 100.0;
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		// Ignore empty lines
		if (line.empty())
		{
			continue;
		}
		ratio my_ratios;
		int uc_count = 0, lc_count = 0;

		// Checks string for upper and lower case letters, and increments respective counts
		for (auto &l : line)
		{
			if (isalpha(l))
			{
				if (isupper(l))
				{
					++uc_count;
				}
				else
				{
					++lc_count;
				}
			}
		}

		// Sets the ratios
		double size = line.size();
		my_ratios.uc = set_ratio(uc_count, size);
		my_ratios.lc = set_ratio(lc_count, size);

		// Outputs the percentage ratios to a percision of 2
		cout.precision(2);
		cout << "lowercase: " << fixed << calc_percent_ratio(my_ratios.lc) << " uppercase: " << calc_percent_ratio(my_ratios.uc) << endl;
	}
	return 0;
}