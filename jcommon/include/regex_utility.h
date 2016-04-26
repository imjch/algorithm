//
// Created by jc on 16-4-26.
//

#ifndef LIBRARY_REGEX_UTILITY_H
#define LIBRARY_REGEX_UTILITY_H
#include <string>
#include <regex>
class regex_utility {
public:
    static bool is_matched(const std::string& str,const std::string& regex_str);
    static bool is_matched(const char* str,const char* regex_str);
};


#endif //LIBRARY_REGEX_UTILITY_H
