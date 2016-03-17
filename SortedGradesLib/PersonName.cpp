#include "stdafx.h"
#include "PersonName.h"

using namespace SortedGradesLib;

PersonName::PersonName(std::wstring first, std::wstring last)
	: m_lastName(last), m_firstName(first)
{
}


PersonName::~PersonName()
{
}

bool PersonName::operator<(const PersonName& other) const
{
	if (m_lastName < other.m_lastName)
	{
		return true;
	}
	if (m_lastName == other.m_lastName)
	{
		return m_firstName < other.m_firstName;
	}
	return false;
}

bool PersonName::operator == (const PersonName& other) const
{
	return m_firstName == other.m_firstName && m_lastName == other.m_lastName;
}
