
class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        rel = 0

        r = len(board)
        if r == 0:
            return rel
        c = len(board[0])
        if c == 0:
            return rel

        for i in range(r):
            for j in range(c):

                if (board[i][j] == 'X' and
                        i > 0 and board[i-1][j] != 'X' and
                        j > 0 and board[i][j-1] != 'X'):
                    rel += 1

                if (board[i][j] == 'X' and
                        (i == 0 and j > 0 and board[i][j-1] != 'X' or
                         j == 0 and i > 0 and board[i-1][j] != 'X')):
                    rel += 1

                if board[i][j] == 'X' and i == 0 and j == 0:
                    rel += 1

        return rel


if __name__ == '__main__':
    demo = Solution()

    board = [['X', '.', '.', 'X'],
             ['X', '.', '.', 'X'],
             ['.', '.', '.', 'X']]

    print demo.countBattleships(board)
