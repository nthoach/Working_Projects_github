#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

// ---------- Ford–Johnson-style Sort for Vector ----------

std::vector<int> fordJohnsonSortVector(const std::vector<int>& input)
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

    std::vector<int> sortedLeaders = fordJohnsonSortVector(leaders);

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

std::deque<int> fordJohnsonSortDeque(const std::deque<int>& input)
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

    std::deque<int> sortedLeaders = fordJohnsonSortDeque(leaders);

    for (size_t i = 0; i < followers.size(); ++i)
	{
        int value = followers[i];
        std::deque<int>::iterator pos = std::lower_bound(sortedLeaders.begin(), sortedLeaders.end(), value);
        sortedLeaders.insert(pos, value);
    }

    return sortedLeaders;
}

// ---------- Print Functions ----------

void printVector(const std::vector<int>& vec, const std::string& label)
{
    std::cout << label;
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void printDeque(const std::deque<int>& deq, const std::string& label)
{
    std::cout << label;
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << " ";
    std::cout << std::endl;
}

// ---------- Main ----------

int main() {
    int data[] = {9, 3, 7, 1, 4, 6, 8, 2, 5};

    std::vector<int> vec(data, data + 9);
    std::deque<int> deq(data, data + 9);

    std::vector<int> sortedVec = fordJohnsonSortVector(vec);
    std::deque<int> sortedDeq = fordJohnsonSortDeque(deq);

    printVector(vec, "Original Vector: ");
    printVector(sortedVec, "Sorted Vector:   ");

    printDeque(deq, "Original Deque:  ");
    printDeque(sortedDeq, "Sorted Deque:    ");

    return 0;
}
