#include "HeapSort.h"

//template <class T> 
//HeapSort<T>::HeapSort(const Heap <T> *heap_) {
//	this->heap = new Heap<T>(*heap_);
//}
//
//template <class T>
//HeapSort<T>::~HeapSort()
//{
//	delete heap;
//}
//
//template <class T>
//void HeapSort<T>::sort() {
//	//heap->build_heap(a);
//	for (uint i = heap->get_lenght(); i >= heap->INDEX_ROOT + 1; --i) {
//		uint index_root = heap->INDEX_ROOT;
//		//std::swap(heap->store[heap->INDEX_ROOT], heap->store[i]);
//		heap->swap(index_root, i);
//		heap->decrease_size();
//
//		heap->heapify(index_root);
//	}
//}