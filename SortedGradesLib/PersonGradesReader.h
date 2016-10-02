#pragma once

#ifndef SORTEDGRADELIB_PERSONGRADESREADER_H
#define SORTEDGRADELIB_PERSONGRADESREADER_H

#include "PersonName.h"
#include "PersonGrade.h"

#include <istream>
#include <vector>
#include <boost/optional.hpp>

namespace SortedGradesLib
{
	class PersonGradesReader
	{
	public:
		PersonGradesReader();
		~PersonGradesReader();

		static std::vector<PersonGrade> Read(std::wistream& input);

	};

}

#endif
