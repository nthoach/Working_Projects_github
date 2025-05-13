// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>

class PmergeMe
{
	private:

	public:
	    PmergeMe();
	    ~PmergeMe();

		std::vector<int> fordJohnsonSort(const std::vector<int>& input);
		std::deque<int> fordJohnsonSort(const std::deque<int>& input);
};

#endif
