# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Do an inorder traversal of the tree
    # Iterate through the inorder traversal and check if it is sorted
    # A BST will always return a sorted list as it's inorder traversal
    def isValidBST(self, root: TreeNode) -> bool:
        self.inorder_set = []

        def inorder(root):
            if(root is None):
                return
            else:
                inorder(root.left)
                self.inorder_set.append(root.val)
                inorder(root.right)

        inorder(root)

        for i in range(len(self.inorder_set)-1):
            if(self.inorder_set[i]>=self.inorder_set[i+1]):
                return False
        return True
