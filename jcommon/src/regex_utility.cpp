//
// Created by jc on 16-4-26.
//

#include "regex_utility.h"
 bool regex_utility::is_matched(const std::string& str,const std::string& regex_str){
    return std::regex_match(str,std::regex(regex_str));
}
bool regex_utility::is_matched(const char* str,const char* regex_str){
    return std::regex_match(str,std::regex(std::string(regex_str)));
}