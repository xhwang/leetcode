class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        l = range(1, N+1)
        num = range(1, N+1)

        return self.recursive(l, num)

    def recursive(self, l, num):

        rel = 0
        if len(l) == 1:
            if self.condition(l[0], num[0]):
                return 1
            else:
                return 0

        for i in num:
            if self.condition(l[0], i):
                # deep copy
                t = list(num)
                t.remove(i)
                rel += self.recursive(l[1::], t)
        return rel

    def condition(self, ith, i):
        return ith % i == 0 or i % ith == 0


if __name__ == '__main__':
    demo = Solution()

    print demo.countArrangement(5)
