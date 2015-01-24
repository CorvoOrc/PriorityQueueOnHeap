#include "PriorityQueue.h"

template <class T>
PriorityQueue<T>::PriorityQueue(const Heap <T> &heap_):Heap<T>(heap_) {
}

template <class T>
PriorityQueue<T>::PriorityQueue(const uint &lenght_, const T *data_, const Type &type_):Heap<T>(lenght_, data_, type_) {
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
}

template <class T>
T PriorityQueue<T>::heap_root() {
	return data[INDEX_ROOT];
}

template <class T>
T PriorityQueue<T>::heap_extract_root() {
	if (get_size() < MIN_HEAP_SIZE)
		throw std::out_of_range("queue is empty");

	T max = heap_root();

	data[INDEX_ROOT] = data[get_size()];
	decrease_size();

	uint index_root = INDEX_ROOT;
	heapify(index_root);

	return max;
}

template <class T>
void PriorityQueue<T>::heap_increase_key(uint i, const T &key) {
	if (key < data[i])
		throw std::runtime_error("new key less current");

	data[i] = key;
	for (; i > INDEX_ROOT && data[parent(i)] < data[i]; i = parent(i))
		swap(i, parent(i));
		//std::swap(data[i], data[parent(i)]);

	if (get_coef() == -1)
		build_heap();
}

template <class T>
void PriorityQueue<T>::heap_insert(const T &key) {
	increase_size();
	data[get_size()] = -INFINITY;

	try{
		heap_increase_key(get_size(), key);
	}
	catch (std::runtime_error &e) {
		throw std::runtime_error(e.what());
	}
}

template PriorityQueue < int >;
template PriorityQueue < float >;
template PriorityQueue < double >;
template PriorityQueue < char >;
// ... add own data type
