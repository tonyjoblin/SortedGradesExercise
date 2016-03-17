#pragma once

#ifndef SORTEDGRADELIB_OUTPUTFILENAME_H
#define SORTEDGRADELIB_OUTPUTFILENAME_H

#include <string>

namespace SortedGradesLib
{
	class OutputFileName
	{
	public:
		static std::wstring Get(const std::wstring& inputFileName);
	};
}

#endif
