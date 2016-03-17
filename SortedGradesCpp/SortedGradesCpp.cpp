// SortedGradesCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include "../SortedGradesLib/PersonGradesReader.h"
#include "../SortedGradesLib/PersonGradesWriter.h"
#include "../SortedGradesLib/OutputFileName.h"

using namespace std;

using namespace SortedGradesLib;

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

void ReadSortAndWritePersonGrades(wistream& input, wostream& output)
{
	PersonGradesReader reader;
	reader.ReadLines(input);
	PersonGradesWriter writer;
	writer.Write(output, reader.m_grades);
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
	const wstring sortedGradesFileName = OutputFileName::Get(gradesFile);

	std::wifstream input;
	input.open(gradesFile.c_str());
	if (!input.good())
	{
		wcout << L"Error: Cannot open grades file " << gradesFile.c_str() << endl; 
		return 1;
	}

	std::wofstream output;
	output.open(sortedGradesFileName.c_str());
	if (!output.good())
	{
		input.close();
		wcout << L"Error: Cannot open output file " << sortedGradesFileName.c_str() << endl;
		return 1;
	}

	ReadSortAndWritePersonGrades(input, output);

	input.close();
	output.close();

	return 0;
}

