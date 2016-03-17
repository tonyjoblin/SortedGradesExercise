#include "stdafx.h"

#include "PersonGradesReader.h"

#include <sstream>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

namespace SortedGradesLib
{
	PersonGradesReader::PersonGradesReader()
	{

	}
	PersonGradesReader::~PersonGradesReader()
	{

	}

	void PersonGradesReader::ReadLines(std::wistream& input)
	{
		while (!input.eof())
		{
			ReadLine(input);
		}
	}

	void PersonGradesReader::ReadLine(std::wistream& input)
	{
		wstring line;
		getline(input, line);

		wistringstream lineStream(line);

		wstring lastName;
		getline(lineStream, lastName, L',');

		wstring firstName;
		getline(lineStream, firstName, L',');

		float grade = -1;
		lineStream >> grade;

		trim(firstName);
		trim(lastName);
		if (firstName.empty() && lastName.empty())
		{
			return;
		}
		PersonName name(firstName, lastName);
		PersonGrade personGrade(name, grade);
		m_grades.push_back(personGrade);
	}

}