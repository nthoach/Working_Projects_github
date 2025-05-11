
// PmergeMe.cpp
#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

// Insertion sort helper
static void insertionSort(std::vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// static void merge(std::vector<int>& arr, int l, int m, int r)
// {
//     std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
//     std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

//     int i = 0, j = 0, k = l;
//     while (i < (int)left.size() && j < (int)right.size()) {
//         if (left[i] <= right[j])
//             arr[k++] = left[i++];
//         else
//             arr[k++] = right[j++];
//     }
//     while (i < (int)left.size()) arr[k++] = left[i++];
//     while (j < (int)right.size()) arr[k++] = right[j++];
// }

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;
    if (arr.size() < 16) {
        insertionSort(arr, 0, arr.size() - 1);
        return;
    }
    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    fordJohnsonSortVector(left);
    fordJohnsonSortVector(right);
    
    std::merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

void PmergeMe::sortVector(std::vector<int>& vec) {
    fordJohnsonSortVector(vec);
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
    std::vector<int> tmp(deq.begin(), deq.end());
    fordJohnsonSortVector(tmp);
    deq.assign(tmp.begin(), tmp.end());
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& sequence)
{
    // Optional: specialize for deque if needed
    (void)sequence; 
}