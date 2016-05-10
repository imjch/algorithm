
#include <algorithm>
#include <string>
#include <cassert>
#include <iterator>
#include <sstream>
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
std::string string_utility::trim_copy(const std::string& str){

}
std::string string_utility::trim(const std::string& str){
	if(str.size()==0){
		return str;
	}
	ssize_t start=0,end=str.size()-1;
	while(str[start]==' '&&start<str.size()){
		start++;
	}	
	while(str[end]==' '&&start<end){
		end--;
	}
	assert(start>=0&&end>=0);

	char buffer[str.size()];
	str.copy(buffer,end-start+1,start);
	return std::string(buffer);
}
 std::string trim(const std::string& str);
int string_utility::toupper(int c){
    if(c<'a'||c>'z'){
        return c;
    }
    return c-32;
}
void string_utility::split(const std::string& s,char c,std::vector<std::string>& v){
    std::string::size_type i = 0;
    std::string::size_type j = s.find(c);

    while (j != std::string::npos) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);

        if (j == std::string::npos)
            v.push_back(s.substr(i, s.length()));
    }
}