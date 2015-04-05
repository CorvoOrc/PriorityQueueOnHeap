__author__ = 'Corvo'

import random
from sort import ISort


class RandomizedQuicksort(ISort):

    def __init__(self):
        pass

    def sort(self, data):
        self.randomized_quicksort(data, 0, len(data)-1)

    def randomized_quicksort(self, a, p, r):
        if p < r:
            q = self.randomized_partition(a, p, r)
            self.randomized_quicksort(a, p, q-1)
            self.randomized_quicksort(a, q+1, r)

    def randomized_partition(self, a, p, r):
        i = random.randrange(p, r)
        a[i], a[r] = a[r], a[i]
        return self.partition(a, p, r)

    def partition(self, a, p, r):
        x = a[r]
        i = p - 1
        for j in range(p, r):
            if a[j] <= x:
                i += 1
                a[i], a[j] = a[j], a[i]
        a[i+1], a[r] = a[r], a[i+1]
        return i + 1


data = [2, 3, 5, 5, 7, 7, 4, 5, 7, 4, 5, 3, 11, 7, -1, -9, 0, -5]
randomized_quicksort = RandomizedQuicksort()
randomized_quicksort.sort(data)
print data
