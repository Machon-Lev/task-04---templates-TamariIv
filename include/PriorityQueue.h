#pragma once

#include <iostream>
#include <list>
#include <exception>


template <typename T>
struct MyComparator {
	bool operator()(T a, T b) const {
		return a < b;
	}
};

// any templates?
template <typename T>
class PriorityQueue {
   
public:
	
// You need to complete the implement : 
	void push(const T& t); 
	T poll();	

private:
// add relevant data members
	std::list<T> elements;

};



template<typename T>
inline void PriorityQueue<T>::push(const T& t)
{
	typename std::list<T>::iterator it = elements.begin();
	while (it != elements.end() && MyComparator<T>(t, *it))
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
