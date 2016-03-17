#include "stdafx.h"
#include "OutputFileName.h"

#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

namespace SortedGradesLib
{
	wstring OutputFileName::Get(const wstring& inputFileName)
	{
		path input(inputFileName);
		auto directory = input.parent_path();
		auto fileNameNoExt = input.stem();
		auto ext = input.extension();

		path output;
		output += directory/fileNameNoExt;
		output += L"-graded";
		output += ext;
		return output.c_str();
	}

}
