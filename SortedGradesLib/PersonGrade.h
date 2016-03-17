#pragma once

#ifndef SORTEDGRADELIB_PERSONGRADE_H
#define SORTEDGRADELIB_PERSONGRADE_H

#include "PersonName.h"

namespace SortedGradesLib
{
	class PersonGrade
	{
	public:
		PersonGrade(PersonName name, float grade);
		~PersonGrade();

		PersonName  m_name;
		float		m_grade;

		bool operator<(const PersonGrade& other) const;
	};

}

#endif
