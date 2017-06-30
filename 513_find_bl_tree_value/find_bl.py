from Queue import Queue


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
        rel = 0
        q = Queue()
        q.put(root)

        n_level = 1
        while not q.empty():

            c_level = n_level
            n_level = 0
            first = True

            while c_level > 0:
                node = q.get()

                if first:
                    rel = node.val
                    first = False

                if node.left:
                    q.put(node.left)
                    n_level += 1
                if node.right:
                    q.put(node.right)
                    n_level += 1

                c_level -= 1

        return rel


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
