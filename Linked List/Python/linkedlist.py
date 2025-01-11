class Node:
    def __init__(self, data):
        self.next = None
        self.data = data


class LinkedList:
    def __init__(self):
        self.head = None

    def insertatstart(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        return

    def insertatindex(self, index, data):
        if index == 0:
            self.insertatstart(data)
            return
        else:
            position = 0
            current_node = self.head
            while current_node is not None and position < index - 1:
                position += 1
                current_node = current_node.next

            if current_node is not None:
                new_node = Node(data)
                new_node.next = current_node.next
                current_node.next = new_node
            else:
                print(f"Index {index} is out of bounds.")

    def insertatend(self, data):
        new_node = Node(data)
        current_node = self.head
        if self.head == None:
            self.head = new_node
            return
        else:
            while current_node.next:
                current_node = current_node.next
            current_node.next = new_node

    def display(self):
        current_node = self.head

        while current_node:
            print(current_node.data, end=",")
            current_node = current_node.next

    def updateNode(self, index, data):
        current_node = self.head
        position = 0
        while current_node != None and position < index - 1:
            position += 1
            current_node = current_node.next
        if current_node.next is not None:
            current_node.next.data = data
        else:
            print("Index is Invalid")

    def size(self):
        current_node = self.head
        position = 0
        while current_node != None:
            position += 1
            current_node = current_node.next
        print("Size:", position)
        return

    def remove_first(self):
        if self.head == None:
            return
        self.head = self.head.next

    def remove_last(self):
        if self.head == None:
            return
        if self.head.next == None:
            self.head = None
        current_node = self.head

        while current_node.next != None and current_node.next.next != None:
            current_node = current_node.next
        current_node.next = None

    def removeatindex(self, index):
        if self.head == None:
            return
        if index == 0:
            self.remove_first()
            return
        current_node = self.head
        position = 0
        while (
            current_node != None
            and current_node.next is not None
            and position < index - 1
        ):
            position += 1
            current_node = current_node.next
        if current_node is not None and current_node.next is not None:
            current_node.next = current_node.next.next


llist = LinkedList()
llist.insertatend("a")
llist.insertatend("b")
llist.insertatstart("c")
llist.insertatend("d")
llist.insertatindex(4, "e")
llist.display()
print("\nUpdated List: ")
llist.updateNode(3, "f")
llist.display()
print("\n")
llist.size()
llist.removeatindex(2)
llist.display()
print("\n")
llist.size()
