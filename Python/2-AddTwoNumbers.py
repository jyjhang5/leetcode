from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def show(self):
        node = self
        while node:
            print(node.val)
            node = node.next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode(0)
        currentNode = result

        carry = 0
        while l1 or l2:
            if l1:
                x = l1.val
                l1 = l1.next
            else:
                x = 0
            if l2:
                y = l2.val
                l2 = l2.next
            else:
                y = 0
            sum = x + y + carry
            carry = sum // 10
            currentNode.val = sum % 10
            if l1 or l2 or carry:
                currentNode.next = ListNode(carry)
                currentNode = currentNode.next
            
        return result


if __name__ == "__main__":

    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)
    # l1.show()

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)
    # l2.show()

    result = Solution().addTwoNumbers(l1, l2)    
    result.show()