class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        rel = 0

        r = len(board)
        c = len(board[0])

        """
        If the condition of Yes has too many variants,
        consider calculating No situations.
        """
        for i in range(r):
            for j in range(c):
                if (board[i][j] == '.'):
                    continue
                if (j > 0 and board[i][j-1] == 'X'):
                    continue
                if (i > 0 and board[i-1][j] == 'X'):
                    continue
                rel += 1

        return rel


if __name__ == '__main__':
    demo = Solution()

    board = [['X', '.', '.', 'X'],
             ['X', '.', '.', 'X'],
             ['.', '.', '.', 'X']]

    print demo.countBattleships(board)
