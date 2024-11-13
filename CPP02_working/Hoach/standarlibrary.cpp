/*

The C++98 standard library is the foundational set of tools and utilities standardized in 1998 to support C++ programming. It includes containers, algorithms, input/output libraries, and utilities for managing resources. Some of the key components in the C++98 standard library are:

1. Containers
Sequence Containers: Store elements in a specific order.
std::vector: Dynamic array with fast random access and amortized constant-time insertion at the end.
std::deque: Double-ended queue with fast insertion and deletion at both ends.
std::list: Doubly linked list with constant-time insertions and deletions anywhere.
Associative Containers: Store elements by key, allowing fast lookups.
std::set: Collection of unique keys, ordered by key.
std::map: Collection of key-value pairs, ordered by key.
std::multiset: Like std::set, but allows duplicate keys.
std::multimap: Like std::map, but allows duplicate keys.
Container Adapters: Provide specific views or behaviors for underlying containers.
std::stack: LIFO stack, typically backed by std::deque.
std::queue: FIFO queue, typically backed by std::deque.
std::priority_queue: Maintains elements in priority order, typically backed by std::vector.
2. Algorithms
Non-modifying algorithms: Functions like std::find, std::count, and std::equal that examine elements but do not modify them.
Modifying algorithms: Functions like std::copy, std::fill, std::replace, and std::swap that change elements in a container.
Sorting and partitioning: Functions such as std::sort, std::stable_sort, std::partial_sort, and std::nth_element.
Searching: Functions like std::binary_search and std::find_if.
Numeric operations: Functions like std::accumulate and std::inner_product.
3. Iterators
Iterators provide a standardized way to access elements in containers. The C++98 standard library includes several types:
Input Iterators: For reading elements.
Output Iterators: For writing elements.
Forward Iterators: For moving in one direction and accessing elements multiple times.
Bidirectional Iterators: For moving both forward and backward.
Random Access Iterators: For moving to any element in constant time.
4. I/O Streams
I/O Stream Classes: Provide formatted and unformatted input and output.
std::istream and std::ostream: Base classes for input and output.
std::cin, std::cout, std::cerr: Standard input, output, and error streams.
std::ifstream and std::ofstream: Input and output for file streams.
std::istringstream and std::ostringstream: String-based input and output.
Stream Manipulators: Functions like std::endl, std::setw, and std::fixed for controlling formatting.
5. String Handling
std::string: The standard string class for handling sequences of characters with dynamic sizing.
String Operations: Functions for manipulating strings, such as substr, find, append, and erase.
6. Utilities
Memory Management: std::allocator for allocating and deallocating memory in containers.
Smart Pointers: C++98 includes only std::auto_ptr, a simple smart pointer with limited functionality (later deprecated and removed in C++11).
Pair: std::pair, a template for storing two heterogeneous objects as a single unit.
Standard Exception Classes: Exception hierarchy based on std::exception, with subclasses like std::runtime_error, std::logic_error, std::out_of_range, and std::invalid_argument.
7. Standard Template Library (STL)
Many of the containers, algorithms, and iterators come from the STL, which became a formal part of the C++98 standard library.
8. C Standard Library Components
The C++98 standard library also includes the C standard library headers, like <cstdlib>, <cstdio>, <cmath>, <ctime>, <cstring>, <cctype>, etc., which are usable in C++ and provide functions for memory allocation, mathematical calculations, character manipulation, time manipulation, and string handling.
Limitations and Differences from Later Versions
Lacks features introduced in C++11 and later, such as std::shared_ptr, std::unique_ptr, std::unordered_map, lambdas, auto, and range-based for loops.
Only provides std::auto_ptr, which has limited and error-prone resource management capabilities compared to later smart pointers.
This library provided a foundation for resource management, algorithmic operations, and data structure handling in C++98, though later C++ standards significantly expanded its functionality.

*/

#include <iostream>

int main()
{
	int* p = new int(10);
	int* ps = new int[10];

	std::cout << *p << *ps << std::endl;

}