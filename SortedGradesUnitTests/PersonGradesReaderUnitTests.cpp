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
	PersonName peter;
	PersonName tom;
	PersonGrade peterGrade;
	PersonGrade tomGrade;
};

BOOST_AUTO_TEST_SUITE(PersonGradesReader_test_suite)

BOOST_FIXTURE_TEST_CASE(ReadSingleLineTest, PersonGradesReaderTestFixture)
{
	PersonGradesReader reader;
	const wstring line = L"JONES,PETER, 70";
	wistringstream input(line);

	reader.ReadLines(input);

	BOOST_REQUIRE_EQUAL(1, reader.m_grades.size());
	BOOST_CHECK_EQUAL(true, peter == reader.m_grades[0].m_name);
}

BOOST_FIXTURE_TEST_CASE(RemovesWhiteSpaceAroundNamesTest, PersonGradesReaderTestFixture)
{
	PersonGradesReader reader;
	const wstring line = L" JONES, PETER, 70";
	wistringstream input(line);

	reader.ReadLines(input);

	BOOST_REQUIRE_EQUAL(1, reader.m_grades.size());
	BOOST_CHECK_EQUAL(true, peter == reader.m_grades[0].m_name);
}

BOOST_FIXTURE_TEST_CASE(ReadMoreThanOneLineTest, PersonGradesReaderTestFixture)
{
	PersonGradesReader reader;
	const wstring data = L" JONES, PETER, 70\nSMITH, TOM, 80";
	wistringstream input(data);

	reader.ReadLines(input);

	BOOST_REQUIRE_EQUAL(2, reader.m_grades.size());
	BOOST_CHECK(reader.m_grades[0].m_name == peterGrade.m_name);
	BOOST_CHECK(reader.m_grades[0].m_grade == peterGrade.m_grade);
	BOOST_CHECK(reader.m_grades[1].m_name == tomGrade.m_name);
	BOOST_CHECK(reader.m_grades[1].m_grade == tomGrade.m_grade);
}

BOOST_FIXTURE_TEST_CASE(SlashRSlashNLineEndingsTest, PersonGradesReaderTestFixture)
{
	PersonGradesReader reader;
	const wstring data = L" JONES, PETER, 70\r\nSMITH, TOM, 80";
	wistringstream input(data);

	reader.ReadLines(input);

	BOOST_REQUIRE_EQUAL(2, reader.m_grades.size());
	BOOST_CHECK(reader.m_grades[0].m_name == peterGrade.m_name);
	BOOST_CHECK(reader.m_grades[0].m_grade == peterGrade.m_grade);
	BOOST_CHECK(reader.m_grades[1].m_name == tomGrade.m_name);
	BOOST_CHECK(reader.m_grades[1].m_grade == tomGrade.m_grade);
}

BOOST_FIXTURE_TEST_CASE(ExtraFieldsTest, PersonGradesReaderTestFixture)
{
	PersonGradesReader reader;
	const wstring data = L" JONES, PETER, 70, somthing\r\nSMITH, TOM, 80";
	wistringstream input(data);

	reader.ReadLines(input);

	BOOST_REQUIRE_EQUAL(2, reader.m_grades.size());
	BOOST_CHECK(reader.m_grades[0].m_name == peterGrade.m_name);
	BOOST_CHECK(reader.m_grades[0].m_grade == peterGrade.m_grade);
	BOOST_CHECK(reader.m_grades[1].m_name == tomGrade.m_name);
	BOOST_CHECK(reader.m_grades[1].m_grade == tomGrade.m_grade);
}

BOOST_FIXTURE_TEST_CASE(BadGradeScoreTest, PersonGradesReaderTestFixture)
{
	PersonGradesReader reader;
	const wstring data = L" JONES, PETER, foobar, somthing\r\nSMITH, TOM, 80";
	wistringstream input(data);

	reader.ReadLines(input);

	BOOST_REQUIRE_EQUAL(2, reader.m_grades.size());
	BOOST_CHECK(reader.m_grades[0].m_name == peterGrade.m_name);
	BOOST_CHECK(reader.m_grades[0].m_grade == -1);
	BOOST_CHECK(reader.m_grades[1].m_name == tomGrade.m_name);
	BOOST_CHECK(reader.m_grades[1].m_grade == tomGrade.m_grade);
}


BOOST_AUTO_TEST_SUITE_END()