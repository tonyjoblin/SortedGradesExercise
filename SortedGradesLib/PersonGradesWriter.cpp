#include "stdafx.h"
#include "PersonGradesWriter.h"

#include <iostream>
#include <algorithm>

using namespace std;

namespace SortedGradesLib
{

	PersonGradesWriter::PersonGradesWriter()
	{
	}


	PersonGradesWriter::~PersonGradesWriter()
	{
	}

	void PersonGradesWriter::Write(std::wostream& output, const std::vector<PersonGrade>& grades) const
	{
		for (const PersonGrade& p : grades)
		{
			Write(output, p);
		}
	}

	void PersonGradesWriter::Write(std::wostream& output, const PersonGrade& personGrade) const
	{
		output << personGrade.m_name.m_lastName
			<< L", "
			<< personGrade.m_name.m_firstName
			<< L", "
			<< personGrade.m_grade
			<< endl;
	}

}
