#pragma once

#include <iostream>
#include <list>
#include <exception>

/**
 * @brief A template struct representing a comparator.
 *
 * The comparator provides a function to compare two elements of type T.
 * The function subtracts b from a and returns the result.
 *
 * @tparam T The type of elements to be compared.
 */
template <typename T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;
	}
};


/**
 * @brief A template class for a priority queue.
 *
 * The priority queue stores elements of type T in a sorted order based on the provided comparator.
 * Elements with lower priority are placed at the front of the queue.
 *
 * @tparam T The type of elements to be stored in the priority queue.
 */
template <typename T>
class PriorityQueue {
   
public:
	
	void push(const T& t); 
	T poll();	

private:
	std::list<T> elements;
	MyComparator<T> compare;
};


/**
 * @brief Pushes an element into the priority queue.
 *
 * The element is inserted at the correct position in the sorted order.
 *
 * @param t The element to be pushed into the priority queue.
 */
template<typename T>
inline void PriorityQueue<T>::push(const T& t)
{
	typename std::list<T>::iterator it = elements.begin();
	while (it != elements.end() && compare(t, *it) < 0)
		++it;
	elements.insert(it, t);
}


/**
 * @brief Retrieves and removes the highest priority element from the priority queue.
 *
 * @return The highest priority element from the priority queue.
 * @throw std::runtime_error if the priority queue is empty.
 */
template<typename T>
inline T PriorityQueue<T>::poll()
{
	if (elements.empty()) {
		throw std::runtime_error("Priority queue is empty");
	}

	T element = elements.front();
	elements.pop_front();
	return element;
}
