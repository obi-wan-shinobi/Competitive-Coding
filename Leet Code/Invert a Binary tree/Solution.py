# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:

        def invert(root):
            if(root is None):
                return None
            else:
                left = invert(root.right)
                right = invert(root.left)
                root.left = left
                root.right = right
                return root

        invert(root)

        return root
                
