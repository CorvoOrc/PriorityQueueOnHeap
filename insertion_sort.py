__author__ = 'Corvo'

from sort import ISort


class Insertionsort(ISort):

    def __init__(self):
        pass

    def sort(self, data):
        self.insertionsort(data)

    def insertionsort(self, a):
        for i in range(0, len(a)):
            x = a[i]
            j = i
            while j > 0 and a[j-1] > x:
                a[j] = a[j-1]
                j -= 1
                a[j] = x


insertionsort = Insertionsort()
data = [2, 3, 5, 5, 7, 7, 4, 5, 7, 4, 5, 3, 11, 7, -5, 0, -10]
insertionsort.sort(data)
print data
