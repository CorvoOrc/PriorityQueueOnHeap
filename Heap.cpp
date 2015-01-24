#include "Heap.h"

template <class T>
Heap<T>::Heap(const uint &lenght_, const T *data_, const Type &type_) {
	this->heap_size = lenght_;
	this->lenght = lenght_;

	try{
		this->data = new T[lenght];
	}
	catch (std::exception e){
		throw std::runtime_error("new data not allocated");
	}

	try{
		memcpy(this->data, data_, sizeof(T) * (this->lenght + INDEX_ROOT));
	}
	catch (std::exception e){
		throw std::runtime_error("memory not allocated");
	}

	this->coef = type_ == nondecreasing ? -1 : 1;

	build_heap();
}

template <class T>
Heap<T>::~Heap() {
	delete[] data;
}

template <class T>
uint Heap<T>::parent(const uint &i) {
	return i >> 1;
}

template <class T>
uint Heap<T>::left(const uint &i) {
	return i << 1;
}

template <class T>
uint Heap<T>::right(const uint &i) {
	return (i << 1) + 1;
}

template <class T>
void Heap<T>::heapify(const uint &i) {
	uint l = left(i);
	uint r = right(i);

	uint largest = i;

	if (l <= heap_size && data[l] * coef > data[i] * coef)
		largest = l;
	if (r <= heap_size && data[r] * coef > data[largest] * coef)
		largest = r;

	if (largest != i) {
		std::swap(data[i], data[largest]);
		heapify(largest);
	}
}

template <class T>
void Heap<T>::build_heap() {
	for (uint i = lenght / 2; i >= INDEX_ROOT; --i)
		heapify(i);
}

template <class T>
void Heap<T>::swap(const uint &i, const uint &j) {
	T tmp = this->data[i];
	this->data[i] = this->data[j];
	this->data[j] = tmp;
}

template <class T>
void Heap<T>::decrease_size() {
	--this->heap_size;
}

template <class T>
void Heap<T>::increase_size() {
	++this->heap_size;
}

template <class T>
uint Heap<T>::get_coef(){
	return this->coef;
}

template <class T>
uint Heap<T>::get_size(){
	return this->heap_size;
}

template <class T>
uint Heap<T>::get_lenght(){
	return this->lenght;
}

template <class T>
const T *Heap<T>::get_data(){
	return this->data;
}

template Heap < int >;
template Heap < float >;
template Heap < double >;
template Heap < char >;
// ... add own data type
