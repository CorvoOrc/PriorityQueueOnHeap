#include "PriorityQueue.h"

//template <class T>
//PriorityQueue<T>::PriorityQueue(const Heap<T> *heap_) {
//	this->heap = new Heap<T>(*heap_);
//}
//
//template <class T>
//PriorityQueue<T>::~PriorityQueue()
//{
//}

//template <class T>
//T PriorityQueue<T>::heap_root() {
//	return heap->store[heap->INDEX_ROOT];
//}
//
//template <class T>
//T PriorityQueue<T>::heap_extract_root() {
//	if (heap->get_size() < heap->MIN_HEAP_SIZE)
//		throw std::out_of_range("queue is empty");
//
//	T max = heap_root();
//	heap->store[heap->INDEX_ROOT] = heap->store[heap->get_size()];
//	heap->decrease_size();
//
//	uint index_root = heap->INDEX_ROOT;
//	heap->heapify(index_root);
//
//	return max;
//}
//
//template <class T>
//void PriorityQueue<T>::heap_increase_key(uint i, T &key) {
//	if (key < heap->store[i])
//		throw std::runtime_error("new key less current");
//
//	heap->store[i] = key;
//	for (; i > heap->INDEX_ROOT && heap->store[heap->parent(i)] * heap->get_coef() < heap->store[i] * heap->get_coef(); i = heap->parent(i))
//		std::swap(heap->store[i], heap->store[heap->parent(i)]);
//}
//
//template <class T>
//void PriorityQueue<T>::heap_insert(T &key) {
//	heap->increase_size();
//	uint i = heap->get_size();
//	heap->store[i] = -INFINITY;
//
//	try{
//		heap_increase_key(heap->heap_size, key);
//	}
//	catch (std::runtime_error &e) {
//		throw std::runtime_error(e.what());
//	}
//}