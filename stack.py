class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node
        self.size += 1

    def pop(self):
        if self.size == 0:
            return None
        temp = self.top
        self.top = self.top.next
        self.size -= 1
        return temp.data
 
stack = Stack()
 
stack.push(10)
stack.push(20)
stack.push(30)
 
print(stack.pop())  
print(stack.pop()) 
print(stack.pop())  
print(stack.pop())   
