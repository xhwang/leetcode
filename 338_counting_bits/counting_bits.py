class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        return [self.getBits(i) for i in range(num+1)]

    def getBits(self, n):
        rel = 0
        while n != 0:
            rel += n % 2
            n = n/2
        return rel


if __name__ == '__main__':
    demo = Solution()
    print demo.countBits(5)
