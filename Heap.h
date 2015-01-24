/*Steshenko Alexander*/
/*
This is implementation binary Heap: watch http://en.wikipedia.org/wiki/Heap_(data_structure)

heapify - O(lgn) = O(h)
build_heap - O(n*lgn)
*/
#pragma once

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
	//Heap();
	Heap(const uint &lenght_, const T *data_, const Type &type_){
		this->heap_size = lenght_;
		this->lenght = lenght_;

		try{
			this->data = new T[lenght];
		}
		catch(std::exception e){
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
	~Heap(){
		delete[] data;
	}

	uint parent(const uint &i){
		return i >> 1;
	}
	uint left(const uint &i){
		return i << 1;
	}
	uint right(const uint &i){
		return (i << 1) + 1;
	}

	void heapify(const uint &i){
		uint l = left(i);
		uint r = right(i);

		uint largest = i;

		if (l <= heap_size && data[l]*coef > data[i]*coef)
			largest = l;
		if (r <= heap_size && data[r]*coef > data[largest]*coef)
			largest = r;

		if (largest != i) {
			std::swap(data[i], data[largest]);
			heapify(largest);
		}
	}

protected:
	void build_heap(){
		for (uint i = lenght / 2; i >= INDEX_ROOT; --i)
			heapify(i);
	}

public:
	void decrease_size(){
		--this->heap_size;
	}
	void increase_size(){
		++this->heap_size;
	}

	void swap(const uint &i, const uint &j){
		T tmp = this->data[i];
		this->data[i] = this->data[j];
		this->data[j] = tmp;
	}

	uint get_coef(){
		return this->coef;
	}
	uint get_size(){
		return this->heap_size;
	}
	uint get_lenght(){
		return this->lenght;
	}
	const T *get_data(){
		return this->data;
	}

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

