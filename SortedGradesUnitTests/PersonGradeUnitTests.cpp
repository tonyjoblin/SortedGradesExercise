#include "stdafx.h"

#include <boost/test/unit_test.hpp>

#include "..\SortedGradesLib\PersonGrade.h"

using namespace boost;
using namespace SortedGradesLib;

BOOST_AUTO_TEST_SUITE(PersonGrade_test_suite)

BOOST_AUTO_TEST_CASE(CtorTest)
{
	PersonName peter(L"Peter", L"Smith");

	PersonGrade petersGrade(peter, 75);

	BOOST_CHECK(peter == petersGrade.m_name);
	BOOST_CHECK_EQUAL(75, petersGrade.m_grade);
}

BOOST_AUTO_TEST_CASE(OperatorLessTest)
{
	PersonName peter(L"Peter", L"Smith");
	PersonName tom(L"Tom", L"Jones");
	PersonGrade petersGrade(peter, 70);
	PersonGrade tomsGrade(tom, 71);

	BOOST_CHECK_EQUAL(true, petersGrade < tomsGrade);
	BOOST_CHECK_EQUAL(false, tomsGrade < petersGrade);
}

BOOST_AUTO_TEST_SUITE_END()