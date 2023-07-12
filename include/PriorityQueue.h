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
	
	// Push template element to the queue
	void push(const T& t); 
	// Get the first element of the queue
	T poll();	

private:
	std::list<T> _elements;
	MyComparator<T> _compare;
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
	typename std::list<T>::iterator it = _elements.begin();
	while (it != _elements.end() && !(_compare(t, *it) < 0))
		++it;
	_elements.insert(it, t);
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
	if (_elements.empty()) {
		throw std::runtime_error("Priority queue is empty");
	}

	T element = _elements.front();
	_elements.pop_front();
	return element;
}
