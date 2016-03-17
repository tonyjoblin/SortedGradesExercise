#include "stdafx.h"

#define BOOST_TEST_MODULE example
#include <boost/test/unit_test.hpp>

#include "..\SortedGradesLib\PersonName.h"

using namespace boost;
using namespace SortedGradesLib;

BOOST_AUTO_TEST_SUITE(PersonName_test_suite)

BOOST_AUTO_TEST_CASE(OperatorLessThanTest)
{
	PersonName peter(L"Peter", L"Smith");
	PersonName tom(L"Tom", L"Jones");

	BOOST_CHECK_EQUAL(true, tom < peter);
	BOOST_CHECK_EQUAL(false, peter < tom);
}

BOOST_AUTO_TEST_CASE(OperatorLessSameNameTest)
{
	PersonName peter(L"Peter", L"Smith");

	BOOST_CHECK_EQUAL(false, peter < peter);
}

BOOST_AUTO_TEST_CASE(OperatorEqualsSameNameTest)
{
	PersonName peter(L"Peter", L"Smith");

	BOOST_CHECK_EQUAL(true, peter == peter);
}

BOOST_AUTO_TEST_CASE(OperatorEqualsDifferentNameTest)
{
	PersonName peter(L"Peter", L"Smith");
	PersonName tom(L"Tom", L"Jones");

	BOOST_CHECK_EQUAL(false, peter == tom);
}

BOOST_AUTO_TEST_SUITE_END()