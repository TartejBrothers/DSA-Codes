class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        if value < self.value:
            if self.left is None:
                self.left = Node(value)
            else:
                self.left.insert(value)
        else:
            if self.right is None:
                self.right = Node(value)
            else:
                self.right.insert(value)


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


tree = Node(5)

tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(8)
tree.insert(9)
tree.insert(6)


BFS(tree)
