#include "stdafx.h"

#include <boost/test/unit_test.hpp>

#include "..\SortedGradesLib\PersonGradesReader.h"

#include <sstream>

using namespace boost;
using namespace SortedGradesLib;

struct PersonGradesReaderTestFixture
{
	PersonGradesReaderTestFixture()
		: peter(L"PETER", L"JONES")
		, tom(L"TOM", L"SMITH")
		, peterGrade(peter, 70)
		, tomGrade(tom, 80)
	{

	}
	~PersonGradesReaderTestFixture()
	{

	}
	const PersonName peter;
	const PersonName tom;
	const PersonGrade peterGrade;
	const PersonGrade tomGrade;

	wistringstream input;
};

BOOST_AUTO_TEST_SUITE(PersonGradesReader_test_suite)

BOOST_FIXTURE_TEST_CASE(ReadSingleLineTest, PersonGradesReaderTestFixture)
{
	input.str(L"JONES,PETER,70");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(1, grades.size());
	BOOST_CHECK_EQUAL(true, peter == grades[0].m_name);
}

BOOST_FIXTURE_TEST_CASE(RemovesWhiteSpaceAroundNamesTest, PersonGradesReaderTestFixture)
{
	input.str(L" JONES , PETER , 70 ");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(1, grades.size());
	BOOST_CHECK_EQUAL(true, peter == grades[0].m_name);
}

BOOST_FIXTURE_TEST_CASE(ReadMoreThanOneLineTest, PersonGradesReaderTestFixture)
{
	input.str(L"JONES, PETER, 70\nSMITH, TOM, 80");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(2, grades.size());
	BOOST_CHECK(grades[0].m_name == peterGrade.m_name);
	BOOST_CHECK(grades[0].m_grade == peterGrade.m_grade);
	BOOST_CHECK(grades[1].m_name == tomGrade.m_name);
	BOOST_CHECK(grades[1].m_grade == tomGrade.m_grade);
}

BOOST_FIXTURE_TEST_CASE(SlashRSlashNLineEndingsTest, PersonGradesReaderTestFixture)
{
	input.str(L"JONES, PETER, 70\r\nSMITH, TOM, 80");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(2, grades.size());
	BOOST_CHECK(grades[0].m_name == peterGrade.m_name);
	BOOST_CHECK(grades[0].m_grade == peterGrade.m_grade);
	BOOST_CHECK(grades[1].m_name == tomGrade.m_name);
	BOOST_CHECK(grades[1].m_grade == tomGrade.m_grade);
}

BOOST_FIXTURE_TEST_CASE(ExtraFieldsTest, PersonGradesReaderTestFixture)
{
	input.str(L" JONES, PETER, 70, somthing\r\nSMITH, TOM, 80");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(2, grades.size());
	BOOST_CHECK(grades[0].m_name == peterGrade.m_name);
	BOOST_CHECK(grades[0].m_grade == peterGrade.m_grade);
	BOOST_CHECK(grades[1].m_name == tomGrade.m_name);
	BOOST_CHECK(grades[1].m_grade == tomGrade.m_grade);
}

BOOST_FIXTURE_TEST_CASE(BadGradeScoreTest, PersonGradesReaderTestFixture)
{
	input.str(L" JONES, PETER, foobar, somthing\r\nSMITH, TOM, 80");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(1, grades.size());
	BOOST_CHECK(grades[0].m_name == tomGrade.m_name);
	BOOST_CHECK(grades[0].m_grade == tomGrade.m_grade);
}

BOOST_FIXTURE_TEST_CASE(ReadEmptyInputStreamTest, PersonGradesReaderTestFixture)
{
	input.str(L"");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(0, grades.size());
}

BOOST_FIXTURE_TEST_CASE(ReadLineOfWhiteSpaceTest, PersonGradesReaderTestFixture)
{
	input.str(L"     ");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(0, grades.size());
}

BOOST_FIXTURE_TEST_CASE(ReadPartialLineTest, PersonGradesReaderTestFixture)
{
	input.str(L"SMITH, ");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(0, grades.size());
}

BOOST_FIXTURE_TEST_CASE(ReadPartialLineTest2, PersonGradesReaderTestFixture)
{
	input.str(L"SMITH, PETER, ");

	auto grades = PersonGradesReader::Read(input);

	BOOST_REQUIRE_EQUAL(0, grades.size());
}


BOOST_AUTO_TEST_SUITE_END()