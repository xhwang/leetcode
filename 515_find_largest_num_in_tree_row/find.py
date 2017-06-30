
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        """
        if root is None:
            return None

        rel = []
        l = [root]

        while len(l) > 0:
        
            num = len(l)

            node = l[0]
            v_max = node.val
            children = filter(None, (node.left, node.right))
            l.extend(children)

            for i in range(1, num):
                node = l[i]
                if node.val > v_max:
                    v_max = node.val
                children = filter(None, (node.left, node.right))
                l.extend(children)

            rel.append(v_max)

            l = l[num:]
        """

        rel = []
        row = [root]

        while any(row):
            rel.append(max(n.val for n in row))
            row = [kid for n in row for kid in (n.left, n.right) if kid]

        return rel
        
if __name__ == '__main__':
    demo = Solution()

    root = TreeNode(1)
    root.left = TreeNode(3)
    root.right = TreeNode(2)
    root.left.left = TreeNode(5)
    root.right.left = TreeNode(3)
    root.right.right = TreeNode(9)

    print demo.largestValues(root)
