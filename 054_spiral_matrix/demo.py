
class Solution(object):

    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        
        row = len(matrix)

        col = len(matrix[0])
        if not col:
            return []

        rstart = 0
        rend = row-1

        cstart = 0
        cend = col-1

        rel = []

        while (rstart <= rend and cstart <= cend):

            for i in xrange(cstart, cend+1):
                rel.append(matrix[rstart][i])
            rstart += 1
            if rstart > rend:
                break

            for i in xrange(rstart, rend+1):
                rel.append(matrix[i][cend])
            cend -= 1
            if cstart > cend:
                break

            for i in xrange(cend, cstart-1, -1):
                rel.append(matrix[rend][i])
            rend -= 1

            for i in xrange(rend, rstart-1, -1):
                rel.append(matrix[i][cstart])
            cstart += 1

        return rel


if __name__ == '__main__':
    demo = Solution()

    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print demo.spiralOrder(matrix)

    matrix = [[1, 2, 3]]
    print demo.spiralOrder(matrix)

    matrix = [[1], [2], [3]]
    print demo.spiralOrder(matrix)
