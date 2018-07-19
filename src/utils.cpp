#include "utils.hpp"


void check_bounds(size_t beg, size_t end)
{
	if (beg < 0 or end < 0)
		throw;
	else if (beg > end)
		throw;
}

std::vector<int> range_impl(int start, int end, int step)
{
	std::vector<int> vec;
	if ((step > 0) &&
			(start > end))
		return vec;
	else if ((step < 0) &&
			(start < end))
		return vec;

	size_t count = abs((start - end)/step);

	vec.reserve(count + 1);

	for(int i = start; ;)
	{
		if (((step > 0) && (i < end)) || 
				((step < 0) && (i > end)))
		{
			vec.push_back(i);
			i += step;
		}
		else
			break;

	}
	return vec;
}

std::vector<int> range(int end)
{
	int start = 0;
	int step = 1;
	return range_impl(start, end, step);
}

std::vector<int> range(int start, int end, int step)
{
	return range_impl(start, end, step);
}

size_t rfind(const std::string &str, const std::string &substr, size_t beg, size_t end)
{
	if (end == std::string::npos)
		end = str.length() - 1;

	if (substr.empty())
		return std::string::npos;
	else
	{
		while(beg <= end)
		{
			size_t found = str.find_last_of(substr[0], end);
			if (found != std::string::npos)
			{
				if (str.substr(found, substr.length()) == substr)
					return found;
				else
					end = found - 1;
			}
			else
				break;
		}
	}
	return std::string::npos;
}

