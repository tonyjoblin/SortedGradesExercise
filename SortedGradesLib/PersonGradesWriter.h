#pragma once

#ifndef SORTEDGRADELIB_PERSONGRADESWRITER_H
#define SORTEDGRADELIB_PERSONGRADESWRITER_H

#include <ostream>
#include <vector>

#include "PersonGrade.h"

namespace SortedGradesLib
{
	class PersonGradesWriter
	{
	public:
		PersonGradesWriter();
		~PersonGradesWriter();

		void Write(std::wostream& output, const std::vector<PersonGrade>& grades) const;

	private:
		void Write(std::wostream& output, const PersonGrade& personGrade) const;
	};
}

#endif