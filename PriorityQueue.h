/*Steshenko Alexander*/
/*
This is implementation PriorityQueue on Heap: data structure,
each element has a priority associated with it. 

heap_root - O(1)
heap_extract_root - O(lgn)
heap_increase_key - O(lgn)
heap_insert - O(lgn)
*/
#pragma once

#include "Heap.h"
#include <iostream>
#include <exception>

template <class T>
class PriorityQueue:public Heap<T>
{
public:
	PriorityQueue(const Heap <T> &heap_);
	PriorityQueue(const uint &lenght_, const T *data_, const Type &type_);
	~PriorityQueue();

	T heap_root();

	T heap_extract_root();

	void heap_increase_key(uint i, const T &key);

	void heap_insert(const T &key);
};

