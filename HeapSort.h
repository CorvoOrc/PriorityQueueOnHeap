/*Steshenko Alexander*/
/*
This is implementation Heapsort (a comparison-based sorting algorithm)
Worst case performance: O(n*lgn)
Worst space complexity: O(1):in-place algorithm
*/
#pragma once
#include "Heap.h"
//#include <exception>
//#include <stdexcept>

template <class T> 
class HeapSort
{
public:
	//HeapSort();
	HeapSort(const Heap <T> *heap_);
	~HeapSort();

	void sort();

	const T *get_data();

private:
	Heap <T> *heap;
};

//#include "HeapSort.cpp"



