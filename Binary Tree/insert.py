class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BT(object):
    def __init__(self, root):
        self.root = Node(root)
    

tree = BT(1)
tree.root.left = Node(2)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)
