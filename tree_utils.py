
from __future__ import print_function

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def build_tree(value):

    if len(value) == 0:
        return None

    from Queue import Queue
    level = Queue()

    num = 0
    root = TreeNode(value[num])
    level.put(root)

    while level.qsize() > 0:
        next_level = Queue()

        while level.qsize() > 0:
            node = level.get()

            num += 1
            if(num >= len(value)):
                return root
            v = value[num]
            if v is not None:
                t = TreeNode(v)
                node.left = t 
                next_level.put(t)

            num += 1
            if(num >= len(value)):
                return root
            v = value[num]
            if v is not None:
                t = TreeNode(v)
                node.right = t
                next_level.put(t)

        level = next_level

    return root


def pre_order(root):

    if root:
        print('{} '.format(root.val))
        pre_order(root.left)
        pre_order(root.right)

def level_order(root):
    q = [root]
    num = 0
    print('[', end='')
    while any(q[num:]):
        node = q[num]

        if node is not None:
            print('{}, '.format(node.val), end='')
            q.append(node.left)
            q.append(node.right)
        else:
            print('null, ', end='')
        num += 1
    print(']')


if __name__ == '__main__':

    values = [6, 2, 10, 1, 4, 8, 11, None, None, 3, 5, 7, 9]
    root = build_tree(values)
    # pre_order(root)
    level_order(root)
