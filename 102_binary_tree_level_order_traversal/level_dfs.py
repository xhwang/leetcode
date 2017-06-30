
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
        if root is None:
            return None

        rel = []
        self.recursive(rel, root, 0)
        return rel

    def recursive(self, rel, root, level):
        # XXX: How many times, data validation check has higher priority
        if root is None:
            return

        if len(rel) <= level:
            rel.append([])
        rel[level].append(root.val)

        self.recursive(rel, root.left, level+1)
        self.recursive(rel, root.right, level+1)


if __name__ == '__main__':
    demo = Solution()

    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)

    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    print demo.levelOrder(root)
