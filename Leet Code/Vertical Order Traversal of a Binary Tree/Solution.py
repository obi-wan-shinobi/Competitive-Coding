# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        # Initiate an empty dict that will store nodes and y co-ordinate at x key
        # Recursively traverse the tree and pass xidx and yidx along with root
        # For each left recursive call, decrement xidx and yidx
        # For each right recursive call, increment xidx and decrement yidx
        # Append the node to list of the appropriate xidx
        # Sort the dict keys and traverse the values
        # sort the list in each xidx by their yidx, if yidx is same, use the node val
        # Traverse this list recursively and append the node values to result list
        hash_map = {}

        def traverse(root, xidx,yidx):
            if(root == None):
                return
            else:
                traverse(root.left, xidx-1, yidx-1)
                if(xidx not in hash_map.keys()):
                    hash_map[xidx] = []
                node_pair = [root, yidx]
                hash_map[xidx].append(node_pair)
                traverse(root.right, xidx+1, yidx-1)

        traverse(root, 0,0)

        result = []

        key_list = sorted(hash_map.keys())

        for keys in key_list:
            nodes = []
            temp = sorted(hash_map[keys], key = lambda x: (x[1], -x[0].val))
            for item in reversed(temp):
                nodes.append(item[0].val)

            result.append(nodes)

        return result
