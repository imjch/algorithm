#include <list>
#include <string>
void _split(std::list<std::string>& list, std::string&s, std::string& sym)
{
    if (s.size() <= sym.size())
    {
        if (s != sym)
        {
            list.push_back(s);
        }
        return;
    }
    int pos = s.find(sym);
    if (pos<0)
    {
        list.push_back(s);
        return;
    }
    list.push_back(s.substr(0, pos));
    s = s.substr(pos + sym.size());
    _split(list, s, sym);
}
std::list<std::string> split(std::string& s,std::string& sym)
{
        std::string tmp;
        std::list<std::string> list;
        _split(list,s,sym);
        return list;
}