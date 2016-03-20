// SortedGradesCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include "../SortedGradesLib/PersonGradesReader.h"
#include "../SortedGradesLib/PersonGradesWriter.h"
#include "../SortedGradesLib/OutputFileName.h"

#include <boost/filesystem.hpp>

using namespace boost::filesystem;
using namespace std;
using namespace SortedGradesLib;

void DisplayUsageInformation(const wchar_t* appName)
{
	// get file name part
	path appPath(appName);
	wcout << L"Usage: " << appPath.filename().c_str() << L" grade-file.txt" << endl;
}

/// TODO this could have a unit test
void ReadSortAndWritePersonGrades(wistream& input, wostream& output)
{
	auto grades = PersonGradesReader::Read(input);

	vector<PersonGrade> sortedGrades(grades);
	std::sort(
		grades.begin(),
		grades.end(),
		[](const PersonGrade& lhs, const PersonGrade& rhs){ return rhs < lhs; }
	);

	PersonGradesWriter writer;
	writer.Write(output, grades);
}

int wmain(int argc, wchar_t* argv[])
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

