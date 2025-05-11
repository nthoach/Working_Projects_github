// main.cpp
#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <sys/time.h>

static bool isValidNumber(const char* str) {
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

static void printSequence(const std::string& label, const std::vector<int>& seq) {
    std::cout << label;
    for (size_t i = 0; i < seq.size(); ++i)
        std::cout << " " << seq[i];
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        if (!isValidNumber(argv[i])) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int val = std::atoi(argv[i]);
        if (val <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(val);
        deq.push_back(val);
    }

    printSequence("Before:", vec);

    PmergeMe sorter;

    timeval start, end;

    gettimeofday(&start, NULL);
    sorter.sortVector(vec);
    gettimeofday(&end, NULL);
    double timeVec = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    sorter.sortDeque(deq);
    gettimeofday(&end, NULL);
    double timeDeq = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    printSequence("After:", vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
              << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : "
              << timeDeq << " us" << std::endl;

    return 0;
}