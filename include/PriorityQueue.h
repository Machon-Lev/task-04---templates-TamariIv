#pragma once

#include <iostream>
#include <list>
#include <exception>


template <typename T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;
	}
};


template <typename T>
class PriorityQueue {
   
public:
	
	void push(const T& t); 
	T poll();	

private:
	std::list<T> elements;
	MyComparator<T> compare;
};



template<typename T>
inline void PriorityQueue<T>::push(const T& t)
{
	typename std::list<T>::iterator it = elements.begin();
	while (it != elements.end() && compare(t, *it) < 0)
		++it;
	elements.insert(it, t);
}

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
