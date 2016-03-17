#include "stdafx.h"

#include <boost/test/unit_test.hpp>

#include "..\SortedGradesLib\OutputFileName.h"

using namespace boost;
using namespace SortedGradesLib;

BOOST_AUTO_TEST_SUITE(OutputFileName_test_suite)

BOOST_AUTO_TEST_CASE(Test)
{
	auto outputFileName = OutputFileName::Get(L"d:\\temp\\grades.txt");
	BOOST_CHECK(outputFileName.compare(L"d:\\temp\\grades-graded.txt") == 0);
}

BOOST_AUTO_TEST_SUITE_END()