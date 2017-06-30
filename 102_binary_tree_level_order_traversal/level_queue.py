
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """

        rel = []

        if root is None:
            return rel

        from Queue import Queue

        level = Queue()
        level.put(root)
        while level.qsize() > 0:

            t = []
            level_num = level.qsize()
            for i in range(level_num):
                node = level.get()
                t.append(node.val)
                if node.left:
                    level.put(node.left)
                if node.right:
                    level.put(node.right)
            rel.append(t)

        return rel


if __name__ == '__main__':
    demo = Solution()

    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)

    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    print demo.levelOrder(root)
