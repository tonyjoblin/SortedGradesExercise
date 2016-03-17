#pragma once

#ifndef SORTEDGRADELIB_PERSONNAME_H
#define SORTEDGRADELIB_PERSONNAME_H

#include <string>

namespace SortedGradesLib
{
	class PersonName
	{
	public:
		PersonName(std::wstring first, std::wstring last);
		~PersonName();

		std::wstring m_lastName;
		std::wstring m_firstName;

		bool operator<(const PersonName& other) const;

		bool operator==(const PersonName& other) const;
	};

}

#endif