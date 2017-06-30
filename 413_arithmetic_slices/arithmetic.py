class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """

        rel = 0
        if len(A) < 3:
            return rel

        num = 0
        diff = A[1] - A[0]
        for i in range(2, len(A)):
            tdiff = A[i] - A[i-1]

            if tdiff == diff:
                num += 1
            else:
                diff = tdiff
                rel += (num + 1) * num / 2
                num = 0

        rel += (num + 1) * num / 2

        return rel

if __name__ == '__main__':
    demo = Solution()

    A = [1, 2, 3, 4]

    print demo.numberOfArithmeticSlices(A)
