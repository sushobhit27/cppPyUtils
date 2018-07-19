#include <iostream>
#include <string>
#include <vector>


std::vector<int> range(int end);
std::vector<int> range(int start, int end, int step = 1);
size_t rfind(const std::string &str, const std::string &substr, size_t beg = 0, size_t end = std::string::npos);

template <typename T,
	 typename Container = std::vector<T> >
	 inline static std::string join(std::vector<T> &container, const std::string &sep = " ")
{
	std::string joined;

	typedef typename Container::const_iterator citr;
	citr start = container.cbegin();
	citr end = container.cend();
	for(; start != end; ++start)
	{
		joined += *start + sep;
	}

	if (!joined.empty())
	{
		std::cout<<joined.find_last_of(sep)<<std::endl;
		std::cout<<sep.length();
		joined = joined.replace(joined.rfind(sep), sep.length(), "");
		std::cout<<"***"<<joined<<"***";
	}
	return joined;
}
