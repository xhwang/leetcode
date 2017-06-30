
# Definition for singly-linked list.

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

# Definition for a binary tree node.

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedListToBST(self, l):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if head is None:
            return None
        l = []
        while head.next is not None:
            l.append(head.val)
            head = head.next
        l.append(head.val)

        root = self.recursive(l)
        return root

    def recursive(self, l):
        idx = len(l) / 2
        root = TreeNode(l[idx])

        if idx > 0:
            root.left = self.recursive(l[0:idx])
        if idx + 1 < len(l):
            root.right = self.recursive(l[idx+1::])

        return root


if __name__ == '__main__':

    l = [1, 2, 3, 4]

    demo = Solution()
    root = demo.sortedListToBST(l)
    print(root)
