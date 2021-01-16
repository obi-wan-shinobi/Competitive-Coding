# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Initialize a global variable gain
# Recursively find depth of left and right subtree and update gain if the sum of left and right subtree is more
# Return the gain and subtract 1 
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.gain = 0

        if(root is None):
            return 0

        def traverse(root):
            if(root is None):
                return 0
            else:
                left_depth = traverse(root.left)
                right_depth = traverse(root.right)
                self.gain = max(self.gain, left_depth+right_depth+1)

                return max(left_depth, right_depth) + 1

        traverse(root)

        return self.gain - 1
