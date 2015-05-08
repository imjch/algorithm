#include <xutility>
namespace imjch{
	//This method could be regard as a extensive version of lower_bound in <algorithm> which returns index where the target shoulde be.
	template <typename RandomAccessIterator, typename T>
	int lower_bound(RandomAccessIterator first, RandomAccessIterator last, const T& value)
	{
		
		typedef typename std::iterator_traits<RandomAccessIterator>::iterator_category iterator_category;
		return _lower_bound(first, last, value, static_cast<typename std::iterator_traits<RandomAccessIterator>::distance_type*>(nullptr), iterator_category());
	}

	template <typename RandomAccessIterator, typename T, class Distance>
	static int _lower_bound(RandomAccessIterator first, RandomAccessIterator last, const T& value, Distance*, std::random_access_iterator_tag)
	{

		Distance len = last - first;
		Distance half;
		RandomAccessIterator middle;
		RandomAccessIterator begin = first;
		while (len > 0)
		{
			half = len >> 1;
			middle = first + half;
			if (*middle < value)
			{
				first = middle + 1;
				len = len - half - 1;
			}
			else
			{
				len = half;
			}
		}
		return std::distance(begin, first);
	}
	template <typename ForwardIterator, typename T, class Distance>
	int _lower_bound(ForwardIterator first, ForwardIterator last, const T& value, Distance*, std::forward_iterator_tag)
	{
		Distance len = std::distance(first,last);
		Distance half;
		ForwardIterator middle;
		ForwardIterator begin = first;
		while (len > 0)
		{
			half = len >> 1;
			middle = first;
			advance(middle, half);
			if (*middle < value)
			{
				first = middle;
				++first;
				len = len - half - 1;
			}
			else
			{
				len = half;
			}
		}
		return std::distance(begin, first);
	}
}