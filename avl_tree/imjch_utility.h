#ifndef IMJCH_UTILITY_H_
#define IMJCH_UTILITY_H_
#include <functional>
namespace imjch_std{
    template <class T,class Compare=std::less<T>>
    const T& max(const T& a, const T& b)
    {
        if (Compare()(a,b))
        {
            return b;
        }
        else
        {
            return a;
        }
    }
}
#endif