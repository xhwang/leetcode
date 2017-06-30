

class Solution:

    '''
    Algorithm Design and Analysis
    # Divide and Conquer
    Integer Division which is similar with `combination sum` which
    requires all combinations
    '''

    def cal(self, n, target):

        # l = [[1] * (n+1)] * (target+1)

        l = [[1,1,1,1,1,1,1],
             [1,1,1,1,1,1,1],
             [1,1,1,1,1,1,1],
             [1,1,1,1,1,1,1],
             [1,1,1,1,1,1,1],
             [1,1,1,1,1,1,1],
             [1,1,1,1,1,1,1]]
        print l

        for i in range(1, target+1):
            for j in range(1, n+1):
                if j > i:
                    l[i][j] = l[i][i]
                else:
                    l[i][j] = l[i-j][j] + l[i][j-1]
            print l

        print l
        

if __name__ == '__main__':

    demo = Solution()
    demo.cal(6, 6)
