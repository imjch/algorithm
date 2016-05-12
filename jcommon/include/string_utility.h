
#ifndef LIBRARY_STRING_UTILITY_H
#define LIBRARY_STRING_UTILITY_H
#include <string>
#include <vector>
class string_utility {
public:
    static std::string to_upper_copy(std::string &str);
    static std::string& to_upper(std::string &str);
    static std::string trim_copy(const std::string& str);
    static std::string trim(const std::string& str);
   
    static void split(const std::string& str,char c,std::vector<std::string>& v);
private:
    static int toupper(int c);
};

#endif //LIBRARY_STRING_UTILITY_H
