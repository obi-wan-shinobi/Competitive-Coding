# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Create a recursive function to append to a list containing string representation
# Append None if the node has an empty child
# Append values in pre-order traversal
# Create a decoding function that recursively calls and creates new nodes
# If the string contains null, make the child None 

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        string = []

        def traverse(root):
            if(root is None):
                string.append(None)
                return

            string.append(root.val)
            traverse(root.left)
            traverse(root.right)

        traverse(root)
        return string

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """

        def decode(data):
            if(len(data) == 0):
                return None
            if(data[0] is None):
                data.pop(0)
                return None
            else:
                root = TreeNode(data[0])
                data.pop(0)
                root.left = decode(data)
                root.right = decode(data)

            return root

        root = decode(data)
        return root
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
