__author__ = 'Corvo'

from sort import ISort


class Countingsort(ISort):

    def __init__(self):
        pass

    def sort(self, data, k, out):
        self.countingsort(data, k, out)

    def countingsort(self, a, k, b):
        c = [0 for i in range(0, k+1)]
        for i in range(0, len(a)):
            c[a[i]] += 1
        for i in range(1, k+1):
            c[i] += c[i-1]
        b[:] = [0 for i in range(0, len(a))]
        for i in range(len(a)-1, -1, -1):
            b[c[a[i]]-1] = a[i]
            c[a[i]] -= 1


data = [2, 3, 5, 5, 7, 7, 4, 5, 7, 4, 5, 3, 11, 7, 1, 2, 9, 50, 0, 17, 0, 6]
sorted_data = []
countingsort = Countingsort()
countingsort.sort(data=data, k=50, out=sorted_data)
print sorted_data
