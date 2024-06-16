class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BT(object):
    def __init__(self, root):
        self.root = Node(root)


def BFS(root):
    if root:
        queue = [root]
        while queue:
            node = queue.pop(0)
            print(node.value, end=" ")
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)


tree = BT(1)
tree.root.left = Node(2)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)


BFS(tree.root)
