
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.l = []
        self.min_val = 0

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        # TODO: <=
        if len(self.l) == 0 or x <= self.min_val:
            self.l.append(self.min_val)
            self.min_val = x

        self.l.append(x)


    def pop(self):
        """
        :rtype: void
        """
        v = self.l.pop()
        if v == self.min_val:
            self.min_val = self.l.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.l[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_val
