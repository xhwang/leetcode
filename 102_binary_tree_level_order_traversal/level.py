
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

        level = [root]
        while len(level) > 0:

            rel.append([i.val for i in level])

            # next_level = []
            # for node in level:
            #     next_level.extend(filter(None, (node.left, node.right)))
            # level = next_level
            level = [kid for n in level for kid in (n.left, n.right) if kid]

        return rel


if __name__ == '__main__':
    demo = Solution()

    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)

    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    print demo.levelOrder(root)
