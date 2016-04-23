//
// Created by jc on 16-4-23.
//

#ifndef LIBRARY_STRING_UTILITY_H
#define LIBRARY_STRING_UTILITY_H
#include <string>

class string_utility {
public:
    static std::string to_upper_copy(std::string &str);

    static std::string &to_upper(std::string &str);

private:
    static int toupper(int c);
};

#endif //LIBRARY_STRING_UTILITY_H
