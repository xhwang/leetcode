class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.l = []
        self.minl = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.l.append(x)
        
        if len(self.minl) == 0 or x < self.minl[-1]:
            self.minl.append(x)
        else:
            self.minl.append(self.minl[-1])
        

    def pop(self):
        """
        :rtype: void
        """
        self.l.pop()
        self.minl.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.l[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.minl[-1]
