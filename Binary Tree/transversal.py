class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BT(object):
    def __init__(self, root):
        self.root = Node(root)

    def print_tree(self, transversal_type):
        if transversal_type == "preorder":
            return self.preorder_print(tree.root, "")
        elif transversal_type == "inorder":
            return self.inorder_print(tree.root, "")
        elif transversal_type == "postorder":
            return self.postorder_print(tree.root, "")
        else:
            return "Transversal type not recognized"

    def preorder_print(self, start, transversal):
        if start:
            transversal += str(start.value) + " "
            transversal = self.preorder_print(start.left, transversal)
            transversal = self.preorder_print(start.right, transversal)
        return transversal


tree = BT(1)
tree.root.left = Node(2)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)


print(tree.print_tree("preorder"))
