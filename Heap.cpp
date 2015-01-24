#include "Heap.h"

//template <class T>
//Heap::Heap(uint lenght_, T *store_, Type type_){
//	this->heap_size = lenght_;
//	this->lenght = lenght_;
//
//	this->store = new T[lenght];
//	for (uint i = INDEX_ROOT; i <= lenght; ++i)
//		this->store[i] = store_[i];
//
//	this->coef = type_ == nondecreasing ? 1 : -1;
//
//	build_heap();
//}

//template <class T>
//Heap<T>::~Heap(){
//}

//template <class T>
//uint Heap<T>::parent(const uint &i) {
//	return i >> 1;
//}
//
//template <class T>
//uint Heap<T>::left(const uint &i) {
//	return i << 1;
//}
//
//template <class T>
//uint Heap<T>::right(const uint &i) {
//	return (i << 1) + 1;
//}

//template <class T>
//void Heap<T>::heapify(const uint &i) {
//	uint l = left(i);
//	uint r = right(i);
//
//	uint largest = i;
//
//	if (l <= heap_size && store[l] * coef > store[i] * coef)
//		largest = l;
//	if (r <= heap_size && store[r] * coef > store[largest] * coef)
//		largest = r;
//
//	if (largest != i) {
//		std::swap(store[i], store[largest]);
//		heapify(largest);
//	}
//}

//template <class T>
//void Heap<T>::build_heap() {
//	for (uint i = lenght/2; i >= INDEX_ROOT; --i)
//		heapify(i);
//}
//
//template <class T>
//void Heap<T>::swap(const uint &i, const uint &j) {
//	int tmp = this->store[i];
//	this->store[i] = this->store[j];
//	this->store[j] = tmp;
//}

//template <class T>
//void Heap<T>::decrease_size() {
//	--this->heap_size;
//}
//
//template <class T>
//void Heap<T>::increase_size() {
//	++this->heap_size;
//}

//template <class T>
//uint Heap<T>::get_coef(){
//	return this->coef;
//}

//template <class T>
//uint Heap<T>::get_size(){
//	return this->heap_size;
//}

//template <class T>
//uint Heap<T>::get_lenght(){
//	return this->lenght;
//}
//
//template <class T>
//const T *Heap<T>::get_data(){
//	return this->store;
//}