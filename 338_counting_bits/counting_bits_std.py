class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        l = [0]
        for i in range(1, num+1):
            # + has higher priority than &
            t = l[i>>1] + (i & 1)
            l.append(t)

        return l

if __name__ == '__main__':
    demo = Solution()
    print demo.countBits(5)
