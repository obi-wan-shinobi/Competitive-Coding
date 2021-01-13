"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
#Loop over the list and create new Node object of every node
#Make a list copy using these objects
#Maintain a dict of old and new node mappings
#Mark the random pointers as null
#After creating a list copy, use the old-new mapping of nodes to assign random pointers
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        output = []
        n = 0
        old_new_map = {}
        if(head is None):
            return head
        new_head = Node(head.val, None, None)
        curr_node = new_head
        curr = head
        old_new_map[head] = new_head
        while curr is not None:
            if(curr.next is None):
                break
            curr = curr.next
            next_node = Node(curr.val, None, None)
            curr_node.next = next_node
            curr_node = next_node
            old_new_map[curr] = curr_node

        old_list_curr = head
        new_list_curr = new_head
        while True:
            if(old_list_curr is None or new_list_curr is None):
                break
            if(old_list_curr.random is not None):
                new_list_curr.random = old_new_map[old_list_curr.random]
            new_list_curr = new_list_curr.next
            old_list_curr = old_list_curr.next

        return new_head
