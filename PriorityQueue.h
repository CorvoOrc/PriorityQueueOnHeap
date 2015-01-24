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
class PriorityQueue:public Heap<T> // How do separate compilation (use .cpp)?
{
public:
	PriorityQueue(const Heap <T> &heap_):Heap<T>(heap_){
	}
	PriorityQueue(const uint &lenght_, const T *data_, const Type &type_):Heap<T>(lenght_, data_, type_){
	}
	~PriorityQueue() {
		delete heap;
	}

	T heap_root() {
		return data[INDEX_ROOT];
	}

	T heap_extract_root(){
		if (get_size() < MIN_HEAP_SIZE)
			throw std::out_of_range("queue is empty");

		T max = heap_root();

		data[INDEX_ROOT] = data[get_size()];
		decrease_size();

		uint index_root = INDEX_ROOT;
		heapify(index_root);

		return max;
	}

	void heap_increase_key(uint i, const int &key){
		if (key < data[i])
			throw std::runtime_error("new key less current");

		data[i] = key;
		for (; i > INDEX_ROOT && data[parent(i)] < data[i]; i = parent(i))
			swap(i, parent(i));
			//std::swap(data[i], data[parent(i)]);

		if (get_coef() == -1)
			build_heap();
	}

	void heap_insert(const int &key){
		increase_size();
		data[get_size()] = -INFINITY;

		try{
			heap_increase_key(get_size(), key);
		}
		catch (std::runtime_error &e) {
			throw std::runtime_error(e.what());
		}
	}
};

