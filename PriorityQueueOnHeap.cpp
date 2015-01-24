/*Steshenko Alexander*/
/*
This is my implementation Priority Queue on Heap.
Theory take from book "Introduction to Algorithms" ,
Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein
*/

#include <iostream>
//#include <conio.h>
#include "HeapSort.h"
#include "PriorityQueue.h"

template <typename T>
void sample_heap_sort(const uint &lenght, const T *data, const Type &type){
	std::cout << std::endl << "Sample of Heap sort" << std::endl << std::endl;

	Heap<double> *heap;
	try{
		heap = new Heap<double>(lenght, data, type);
	}
	catch (std::runtime_error e){
		std::cout << "runtime error in sample_heap_sort:" << e.what() << std::endl;
		return;
	}

	std::cout << "Heap data:" << std::endl;
	const double *data_heap = heap->get_data();
	for (int i = heap->INDEX_ROOT; i <= heap->get_size(); ++i) std::cout << data_heap[i] << " ";
	std::cout << std::endl;

	HeapSort<double> *sort = new HeapSort<double>(heap);

	sort->sort();

	std::cout << "Sort data:" << std::endl;
	const double *result = sort->get_data();
	for (int i = heap->INDEX_ROOT; i <= heap->get_size(); ++i) std::cout << result[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void sample_work_with_priority(const uint &lenght, const T *data, const Type &type){
	std::cout << std::endl << "Sample of work with Priority Queue" << std::endl << std::endl;

	Heap<double> *heap;
	try{
		heap = new Heap<double>(lenght, data, type);
	}
	catch (std::runtime_error e){
		std::cout << "runtime error in sample_work_with_priority:" << e.what() << std::endl;
		return;
	}

	std::cout << "Heap data:" << std::endl;
	const double *data_heap = heap->get_data();
	for (int i = heap->INDEX_ROOT; i <= heap->get_size(); ++i) std::cout << data_heap[i] << " ";
	std::cout << std::endl;

	std::cout << "Priority data:" << std::endl;
	PriorityQueue<double> *priority = new PriorityQueue<double>(*heap/*lenght, a, type*/);
	const double *data_priority = priority->get_data();
	for (int i = priority->INDEX_ROOT; i <= priority->get_size(); ++i) std::cout << data_priority[i] << " ";
	std::cout << std::endl;

	std::cout << "Priority data after insert key 43:" << std::endl;
	try{
		priority->heap_insert(43);
	}
	catch (std::runtime_error e){
		std::cout << "runtime error in sample_work_with_priority:" << e.what() << std::endl;
		return;
	}

	const double *data_after_ins_key = priority->get_data();
	for (int i = priority->INDEX_ROOT; i <= priority->get_size(); ++i) std::cout << data_after_ins_key[i] << " ";
	std::cout << std::endl;

	T root;
	try{
		root = priority->heap_extract_root();
	}
	catch (std::out_of_range e){
		std::cout << "out_of_range in sample_work_with_priority:" << e.what() << std::endl;
		return;
	}

	std::cout << "root=" << root << std::endl;
	std::cout << "Priority data after extract_root:" << std::endl;
	const double *data_after_extract_root = priority->get_data();
	for (int i = priority->INDEX_ROOT; i <= priority->get_size(); ++i) std::cout << data_after_extract_root[i] << " ";
	std::cout << std::endl;
}

int main()
{
	uint lenght;
	std::cout << "lenght=";
	std::cin >> lenght;

	double *a = { 0 };
	a = new double[lenght + 1];

	std::cout << "data=";
	for (int i = Heap<double>::INDEX_ROOT; i <= lenght; ++i)
		std::cin >> a[i];

	sample_heap_sort(lenght, a, nondecreasing);
	sample_work_with_priority(lenght, a, nonincreasing);

	//_getch();
	return 0;
}
