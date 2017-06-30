class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        # BFS from left to right, the bottom-right must be the last element,
        # similarly, BFS from right to left, the last element must be bl

        # Note: list can also work as FIFO queue
        queue = [root]

        for node in queue:
            # filter function program
            queue += filter(None, (node.right, node.left))

        return node.val


if __name__ == '__main__':
    demo = Solution()

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(4)
    root.right = TreeNode(3)
    root.right.left = TreeNode(5)
    root.right.right = TreeNode(6)
    root.right.left.left = TreeNode(7)

    print demo.findBottomLeftValue(root)
