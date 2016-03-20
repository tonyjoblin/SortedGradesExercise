#include "stdafx.h"

#include <boost/test/unit_test.hpp>

#include "..\SortedGradesLib\PersonGradesWriter.h"

#include <sstream>
#include <vector>

using namespace std;
using namespace boost;
using namespace SortedGradesLib;

struct PersonGradesWriterTestFixture
{
	PersonGradesWriterTestFixture()
		: peter(L"PETER", L"JONES")
		, tom(L"TOM", L"SMITH")
		, peterGrade(peter, 70)
		, tomGrade(tom, 80)
	{

	}
	~PersonGradesWriterTestFixture()
	{

	}
	PersonName peter;
	PersonName tom;
	PersonGrade peterGrade;
	PersonGrade tomGrade;

	vector<PersonGrade> grades;

	PersonGradesWriter writer;

	wostringstream output;
};

BOOST_AUTO_TEST_SUITE(PersonGradesWriter_test_suite)

BOOST_FIXTURE_TEST_CASE(WriteSingleTest, PersonGradesWriterTestFixture)
{
	grades.push_back(peterGrade);

	writer.Write(output, grades);

	wstring result = output.str();
	BOOST_CHECK(L"JONES, PETER, 70\n" == result);
}

BOOST_FIXTURE_TEST_CASE(WriteMoreThanOneTest, PersonGradesWriterTestFixture)
{
	grades.push_back(tomGrade);
	grades.push_back(peterGrade);

	writer.Write(output, grades);

	wstring result = output.str();
	BOOST_CHECK(L"SMITH, TOM, 80\nJONES, PETER, 70\n" == result);
}


BOOST_AUTO_TEST_SUITE_END()