// SortedGradesCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

wstring GetFileName(const wchar_t* appName)
{
	wchar_t fname[_MAX_FNAME];
	wchar_t ext[_MAX_EXT];
	_wsplitpath_s(appName, nullptr, 0, nullptr, 0, fname, _MAX_FNAME, ext, _MAX_EXT);
	return wstring(fname) + wstring(ext);
}

void DisplayUsageInformation(const wchar_t* appName)
{
	// get file name part
	wcout << L"Usage: " << GetFileName(appName).c_str() << L" grade-file.txt" << endl;
}

int _tmain(int argc, wchar_t* argv[])
{
	if (argc != 2)
	{
		wcout << L"Error: incorrect number of arguments provided." << endl;
		DisplayUsageInformation(argv[0]);
		return 1;
	}

	const wstring gradesFile(argv[1]);

	// open file
	// if can't open report error
	wifstream input;
	input.open(gradesFile.c_str());
	if (!input.good())
	{
		wcout << L"Error: Cannot open grades file " << gradesFile.c_str() << endl; 
		return 1;
	}

	while (!input.eof())
	{
		wstring lastName;
		getline(input, lastName, L',');

		wstring firstName;
		getline(input, firstName, L',');
		
		float grade;
		input >> grade;

		if (input.good())
		{
			wcout << lastName << L"|" << firstName << L"|" << grade << endl;
		}

		input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// for each line
	// parse into parts
	// create a object for each data
	// sort
	// dump output

	input.close();

	return 0;
}

