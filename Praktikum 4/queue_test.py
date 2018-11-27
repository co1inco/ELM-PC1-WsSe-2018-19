from tkinter import *


class queue():
    def __init__(self, max_items=100):
        self.max = max_items

        self.queueList = [None] * (max_items+1)
        self.currentFirst = 0
        self.currentLast = 0

    def increase(self, i):
        if i == self.max:
            i = 0
        else:
            i = i + 1
        return i

    def getCount(self):
        if not self.isEmty():
            if self.currentFirst < self.currentLast:
                return ((self.max - self.currentLast) + self.currentFirst)
            else:
                return (self.currentFirst - self.currentLast)
        else:
            return 0

    def isEmty(self):
        if self.currentFirst == self.currentLast:
            return True
        return False

    def isFull(self):
        if self.currentFirst+1 == self.currentLast:
            return True
        elif self.currentFirst == self.max and self.currentLast == 0:
            return True           
        return False

    def addItem(self, item):
        if not self.isFull():
            self.queueList[self.currentFirst] = item
            self.currentFirst = self.increase(self.currentFirst)
            return True
        else:
            return False

    def getItem(self):
        if not self.isEmty():
            rt = self.queueList[self.currentLast]
            self.queueList[self.currentLast] = None
            self.currentLast = self.increase(self.currentLast)
            return rt
        else:
            return False

    def printQueue(self):
        print("Debug Queue")
        print("Max: Index(%i) %i" % (self.max, self.max+1))
        print("Next Add: %i" % self.currentFirst)
        print("Next Get: %i" % self.currentLast)
        print("ItemsCount: %i" % self.getCount())
        print("---Queue Start---")
        if not self.isEmty():
            for i, j in enumerate(self.queueList):
                print(("Index: %02i | " % i) + str(j))
        else:
            print("Emty")
        print("---Queue Emty---")
        
if __name__ == '__main__':
    q = queue(16)

    for i in range(0, 16):
        q.addItem(i)

    q.printQueue()

    print(q.addItem("a"))
    print(q.getItem())
    print(q.getItem())
    q.printQueue()
    print(q.addItem("b"))
    print(q.addItem("c"))
    print(q.addItem("d"))
    q.printQueue()


            
