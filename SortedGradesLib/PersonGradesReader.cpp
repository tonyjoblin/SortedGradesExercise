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

	std::vector<PersonGrade> PersonGradesReader::Read(std::wistream& input)
	{
		std::vector<PersonGrade> grades;
		while (!input.eof())
		{
			ReadLine(input, grades);
		}
		return grades;
	}

	static bool ValidateGrade(const float& grade)
	{
		return 0 <= grade;
	}

	static bool ValidateName(const wstring& firstName, const wstring& lastName)
	{
		return !firstName.empty() && !lastName.empty();
	}

	static bool ValidatePersonGradeValues(const wstring& firstName, const wstring& lastName, const float& grade)
	{
		return ValidateGrade(grade) && ValidateName(firstName, lastName);
	}

	void PersonGradesReader::ReadLine(std::wistream& input, std::vector<PersonGrade>& grades)
	{
		wstring line;
		getline(input, line);

		wistringstream lineStream(line);

		wstring lastName;
		getline(lineStream, lastName, L',');
		trim(lastName);

		wstring firstName;
		getline(lineStream, firstName, L',');
		trim(firstName);

		float grade = -1;
		lineStream >> grade;

		if (!ValidatePersonGradeValues(firstName, lastName, grade))
		{
			return;
		}
		
		PersonName name(firstName, lastName);
		PersonGrade personGrade(name, grade);
		grades.push_back(personGrade);
	}

}