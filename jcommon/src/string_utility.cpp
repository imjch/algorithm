//
// Created by jc on 16-4-23.
//

#include <algorithm>
#include <string>
#include "string_utility.h"

std::string string_utility::to_upper_copy(std::string& str){
    std::string s(str);
    std::transform(str.begin(),str.end(),s.begin(),string_utility::toupper);
    return s;
}
std::string& string_utility::to_upper(std::string& str){
    std::transform(str.begin(),str.end(),str.begin(),string_utility::toupper);
    return str;
}

int string_utility::toupper(int c){
    if(c<'a'||c>'z'){
        return c;
    }
    return c-32;
}