# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        head = ListNode()
        ans = head
        first, second = l1, l2
        while (True):
            if(first is None or second is None):
                curr = second
                if(second is None):
                    curr = first
                while(curr is not None):
                    temp = curr.val + carry
                    carry = int(temp/10)
                    temp = temp%10
                    ans.next = ListNode(temp)
                    curr = curr.next
                    ans = ans.next
                if(curr is None):
                    break
            else:
                temp_sum = first.val + second.val + carry
                carry = int(temp_sum/10)
                temp_sum = temp_sum%10
                new_node = ListNode(temp_sum)
                ans.next = new_node
                first = first.next
                second = second.next
                ans = ans.next

        head = head.next
        if(carry):
            new_node = ListNode(carry)
            ans.next = new_node

        return head
