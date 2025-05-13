
// PmergeMe.cpp
#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

// ---------- Ford–Johnson-style Sort for Vector ----------

std::vector<int> PmergeMe::fordJohnsonSort(const std::vector<int>& input)
{
    if (input.size() <= 1)
        return input;

    std::vector<int> followers;
    std::vector<int> leaders;

    for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
        int a = input[i];
        int b = input[i + 1];
        if (a < b)
		{
            followers.push_back(a);
            leaders.push_back(b);
        }
		else
		{
            followers.push_back(b);
            leaders.push_back(a);
        }
    }

    if (input.size() % 2 != 0)
        leaders.push_back(input.back());

    std::vector<int> sortedLeaders = fordJohnsonSort(leaders);

    // Binary insertion
    for (size_t i = 0; i < followers.size(); ++i)
	{
        int value = followers[i];
        std::vector<int>::iterator pos = std::lower_bound(sortedLeaders.begin(), sortedLeaders.end(), value);
        sortedLeaders.insert(pos, value);
    }

    return sortedLeaders;
}

// ---------- Ford–Johnson-style Sort for Deque ----------

std::deque<int> PmergeMe::fordJohnsonSort(const std::deque<int>& input)
{
    if (input.size() <= 1)
        return input;

    std::deque<int> followers;
    std::deque<int> leaders;

    for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
        int a = input[i];
        int b = input[i + 1];
        if (a < b)
		{
            followers.push_back(a);
            leaders.push_back(b);
        } else
		{
            followers.push_back(b);
            leaders.push_back(a);
        }
    }

    if (input.size() % 2 != 0)
        leaders.push_back(input.back());

    std::deque<int> sortedLeaders = fordJohnsonSort(leaders);

    for (size_t i = 0; i < followers.size(); ++i)
	{
        int value = followers[i];
        std::deque<int>::iterator pos = std::lower_bound(sortedLeaders.begin(), sortedLeaders.end(), value);
        sortedLeaders.insert(pos, value);
    }

    return sortedLeaders;
}