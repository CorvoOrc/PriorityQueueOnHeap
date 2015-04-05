__author__ = 'Corvo'

from sort import ISort


class Mergesort(ISort):

    def __init__(self):
        pass

    def sort(self, data):
        self.mergesort(data)

    def mergesort(self, a):
        if len(a) > 1:
            mid = len(a)/2
            l = a[mid:]
            r = a[:mid]
            self.mergesort(l)
            self.mergesort(r)
            self.merge_part(a, l, r)

    def merge_part(self, a, left_half, right_half):
        i, j, k = 0, 0, 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                a[k] = left_half[i]
                i += 1
            else:
                a[k] = right_half[j]
                j += 1
            k += 1
        while i < len(left_half):
            a[k] = left_half[i]
            i, k = i+1, k+1
        while j < len(right_half):
            a[k] = right_half[j]
            j, k = j+1, k+1


data = [1, 9, 5, 8, 3, 2, 6, 7, 5, 8, -1, -3, -5, 10, 0]
mergesort = Mergesort()
mergesort.sort(data)
print data
