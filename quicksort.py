__author__ = 'Corvo'

from sort import ISort


class Quicksort(ISort):

    def __init__(self):
        pass

    def sort(self, data):
        self.quicksort(data, 0, len(data)-1)

    def quicksort(self, a, p, r):
        if p < r:
            q = self.partition(a, p, r)
            self.quicksort(a, p, q-1)
            self.quicksort(a, q+1, r)

    def partition(self, a, p, r):
        x = a[r]
        i = p - 1
        for j in range(p, r):
            if a[j] <= x:
                i += 1
                a[i], a[j] = a[j], a[i]
        a[i+1], a[r] = a[r], a[i+1]
        return i + 1

    def test(self):

        self.quicksort(data, 0, len(data)-1)
        return data


data = [2, 3, 5, 5, 7, 7, 4, 5, 7, 4, 5, 3, 11, 7, -5]
quicksort = Quicksort()
quicksort.sort(data)
print data
