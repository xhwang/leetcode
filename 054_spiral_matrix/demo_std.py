
class Solution(object):

    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        rel = []

        while matrix:

            rel.extend(matrix.pop(0))

            if matrix and matrix[0]:
                for row in matrix:
                    rel.append(row.pop(-1))
        
            if matrix:
                rel.extend(matrix.pop(-1)[::-1])

            if matrix and matrix[0]:
                for row in matrix[::-1]:
                    rel.append(row.pop(0))

        return rel


if __name__ == '__main__':
    demo = Solution()

    """
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print demo.spiralOrder(matrix)

    matrix = [[1, 2, 3]]
    print demo.spiralOrder(matrix)

    matrix = [[1], [2], [3]]
    print demo.spiralOrder(matrix)
    """

    matrix = [[1, 2], [3, 4]]
    print demo.spiralOrder(matrix)
