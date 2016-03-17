#include "stdafx.h"

#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>

#include "..\SortedGradesLib\PersonName.h"

using namespace boost;
using namespace SortedGradesLib;

BOOST_AUTO_TEST_SUITE(PersonName_test_suite)

BOOST_AUTO_TEST_CASE(OperatorLessThanTest)
{
	PersonName PeterSmith(L"Peter", L"Smith");
	PersonName TomJones(L"Tom", L"Jones");
	BOOST_CHECK_EQUAL(true, TomJones < PeterSmith);
}

BOOST_AUTO_TEST_SUITE_END()