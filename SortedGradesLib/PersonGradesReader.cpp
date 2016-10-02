#include "stdafx.h"

#include "PersonGradesReader.h"

#include <sstream>
#include <tuple>
#include <boost/algorithm/string.hpp>
#include <boost/optional.hpp>

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

	static wstring ReadNameField(wistringstream& stream)
	{
		wstring name;
		getline(stream, name, L',');
		trim(name);
		return name;
	}

	static float ReadGrade(wistringstream& stream)
	{
		float grade = -1;
		stream >> grade;
		return grade;
	}

	static tuple<wstring, wstring, float> ReadPersonGradeFieldData(wistream& input)
	{
		wstring line;
		getline(input, line);
		wistringstream lineStream(line);

		wstring lastName = ReadNameField(lineStream);
		wstring firstName = ReadNameField(lineStream);
		float grade = ReadGrade(lineStream);

		return make_tuple(lastName, firstName, grade);
	}

	static optional<PersonGrade> ReadPersonGradeLine(wistream& input)
	{
		wstring lastName, firstName;
		float grade;
		tie(lastName, firstName, grade) = ReadPersonGradeFieldData(input);

		if (!ValidatePersonGradeValues(firstName, lastName, grade))
		{
			return boost::none;
		}

		PersonName name(firstName, lastName);
		return PersonGrade(name, grade);
	}

	static void ReadPersonGradeFromLineAndAddToResults(wistream& input, vector<PersonGrade>& grades)
	{
		optional<PersonGrade> personGrade = ReadPersonGradeLine(input);
		if (personGrade)
		{
			grades.push_back(*personGrade);
		}
	}

	vector<PersonGrade> PersonGradesReader::Read(wistream& input)
	{
		std::vector<PersonGrade> grades;
		while (!input.eof())
		{
			ReadPersonGradeFromLineAndAddToResults(input, grades);
		}
		return grades;
	}
}