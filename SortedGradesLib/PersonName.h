#pragma once

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

	private:
		PersonName();
	};

}
