#pragma once

#ifndef SORTEDGRADELIB_PERSONGRADESREADER_H
#define SORTEDGRADELIB_PERSONGRADESREADER_H

#include "PersonName.h"
#include "PersonGrade.h"

#include <istream>
#include <vector>

using namespace std;

namespace SortedGradesLib
{
	class PersonGradesReader
	{
	public:
		PersonGradesReader();
		~PersonGradesReader();

		void ReadLines(std::wistream& input);

		std::vector<PersonGrade> m_grades;

	private:
		void ReadLine(std::wistream& input);
	};

}

#endif
