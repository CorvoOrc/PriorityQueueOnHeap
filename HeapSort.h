/*Steshenko Alexander*/
/*
This is implementation Heapsort (a comparison-based sorting algorithm)
Worst case performance: O(n*lgn)
Worst space complexity: O(1):in-place algorithm
*/
#pragma once
#include "Heap.h"
#include <exception>

template <class T> class HeapSort
{
public:
	HeapSort(const Heap <T> *heap_) {
		try{
			this->heap = new Heap<T>(*heap_);
		}
		catch (std::runtime_error run_err){
			throw std::runtime_error(run_err.what());
		}
	}
	~HeapSort(){
		delete heap;
	}

	void sort() {
		//heap->build_heap(a);
		for (uint i = heap->get_lenght(); i >= heap->INDEX_ROOT + 1; --i) {
			uint index_root = heap->INDEX_ROOT;
			//std::swap(heap->store[heap->INDEX_ROOT], heap->store[i]);
			heap->swap(index_root, i);
			heap->decrease_size();

			heap->heapify(index_root);
		}
	}

	const T *get_data() {
		return this->heap->get_data();
	}

private:
	Heap <T> *heap;
};

//#include "HeapSort.cpp"



