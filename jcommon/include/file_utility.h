#ifndef LIBRARY_FILE_UTILITY_H
#define LIBRARY_FILE_UTILITY_H
#include <fstream>
class file_utility
{
public:
	static std::ifstream::pos_type filesize(std::ifstream& infile);
};
#endif