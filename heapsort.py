__author__ = 'Corvo'

from sort import ISort


class Heapsort(ISort):

    def __init__(self):
        self.heap_size = 0

    def sort(self, data):
        self.heapsort(data)

    def parent(self, i):
        return i/2

    def left(self, i):
        return i*2

    def right(self, i):
        return i*2 + 1

    def heapsort(self, a):
        self.build_max_heap(a)
        for i in range(len(a)-1, 0, -1):
            a[i], a[0] = a[0], a[i]
            self.heap_size -= 1
            self.max_heapify(a, 0)

    def build_max_heap(self, a):
        self.heap_size = len(a)
        for i in range(self.heap_size/2 - 1, -1, -1):
            self.max_heapify(a, i)

    def max_heapify(self, a, i):
        l, r = self.left(i), self.right(i)
        largest = -1
        if l < self.heap_size and a[l] > a[i]:
            largest = l
        else:
            largest = i
        if r < self.heap_size and a[r] > a[largest]:
            largest = r
        if largest != i:
            a[i], a[largest] = a[largest], a[i]
            self.max_heapify(a, largest)


data = [1, 9, 5, 8, 3, 2, 6, 7, 5, 8, -1, -3, -5, 10, 0]
heapsort = Heapsort()
heapsort.sort(data)
print data
