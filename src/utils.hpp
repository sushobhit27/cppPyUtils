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
std::string swapcase(std::string str);
std::string zfill(const std::string &str, size_t width);
bool startswith(const std::string &substr, const std::string &str, size_t beg = 0, size_t end = std::string::npos);
bool endswith(const std::string &substr, const std::string &str, size_t beg = 0, size_t end = std::string::npos);


template <typename T,
    typename Container>
bool is_in(const T &val, 
    Container& container,
    typename std::enable_if<std::is_same<T, typename Container::value_type>::value, T>::type* = nullptr)
{
    return std::find(container.begin(), container.end(), val) != container.end();
}

template <typename T,
    typename Container,
    typename UnaryPredicate>
bool is_in(const T &val, 
    Container& container,
    UnaryPredicate predicate,
    typename std::enable_if<std::is_same<T, typename Container::value_type>::value, T>::type* = nullptr)
{
    return std::find_if(container.begin(), container.end(), predicate) != container.end();
}

template <typename T,
    typename Container>
bool is_in(const T &val, Container& container,
    typename std::enable_if<std::is_same<T, typename Container::key_type>::value, T>::type* = nullptr)
{
    return container.find(val) != container.end();
}

template <typename T,
    typename Container,
    typename UnaryPredicate>
bool is_in(const T &val, 
    Container& container,
    UnaryPredicate predicate,
    typename std::enable_if<std::is_same<T, typename Container::key_type>::value, T>::type* = nullptr)
{
    for (const auto& pair : container)
    {
        if (predicate(pair.first))
            return true;
    }
    return false;
}