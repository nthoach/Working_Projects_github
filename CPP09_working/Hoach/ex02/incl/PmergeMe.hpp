// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sortVector(std::vector<int>& vec);
    void sortDeque(std::deque<int>& deq);

private:
    void fordJohnsonSortVector(std::vector<int>& sequence);
    void fordJohnsonSortDeque(std::deque<int>& sequence);
};

#endif
