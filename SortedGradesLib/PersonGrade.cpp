#include "stdafx.h"
#include "PersonGrade.h"

namespace SortedGradesLib
{

	PersonGrade::PersonGrade(PersonName name, float grade)
		: m_name(name), m_grade(grade)
	{
	}


	PersonGrade::~PersonGrade()
	{
	}

	bool PersonGrade::operator<(const PersonGrade& other) const
	{
		if (m_grade < other.m_grade)
		{
			return true;
		}

		if (other.m_grade < m_grade)
		{
			return false;
		}

		return m_name < other.m_name;
	}

}
