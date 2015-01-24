/*Steshenko Alexander*/
/*
This is implementation binary Heap: watch http://en.wikipedia.org/wiki/Heap_(data_structure)

heapify - O(lgn) = O(h)
build_heap - O(n*lgn)
*/
#pragma once
#include <stdexcept>

typedef unsigned int uint;

enum Type{
	nondecreasing = 0,
	nonincreasing = 1
};

template <class T> 
class Heap
{
public:
	//template<typename T>
	//friend class Priority;
	//Heap(const Heap<T> &);
	Heap(const uint &lenght_, const T *data_, const Type &type_); 
	~Heap();

	uint parent(const uint &i);
	uint left(const uint &i);
	uint right(const uint &i);

	void heapify(const uint &i);

protected:
	void build_heap();

public:
	void decrease_size();
	void increase_size();

	void swap(const uint &i, const uint &j);

	uint get_coef();
	uint get_size();
	uint get_lenght();
	const T *get_data();

public:
	const uint MIN_HEAP_SIZE = 1;
	static const uint INDEX_ROOT = 1;

private:
	uint heap_size;
	uint lenght;
	int coef;
protected:
	T *data;
};

