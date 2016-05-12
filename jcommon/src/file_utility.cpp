#include "file_utility.h"
std::ifstream::pos_type file_utility::filesize(std::ifstream& infile)
{
    std::ifstream::pos_type currentPos=infile.tellg();
    infile.seekg(0,infile.end);
    std::ifstream::pos_type size=infile.tellg();
    infile.seekg(currentPos);
    return size; 
}