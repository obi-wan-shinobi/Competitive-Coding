# Problem

Given the `root` of a binary tree, calculate the __vertical order traversal__ of the binary tree.

For each node at position `(x, y)`, its left and right children will be at positions `(x - 1, y - 1)` and `(x + 1, y - 1)` respectively.

The __vertical order traversal__ of a binary tree is a list of non-empty __reports__ for each unique x-coordinate from left to right. Each __report__ is a list of all nodes at a given x-coordinate. The __report__ should be primarily sorted by y-coordinate from highest y-coordinate to lowest. If any two nodes have the same y-coordinate in the __report__, the node with the smaller value should appear earlier.

Return _the **vertical order traversal** of the binary tree._

#### Example 1:
![](1236_example_1.png)
```
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: Without loss of generality, we can assume the root node is at position (0, 0):
The node with value 9 occurs at position (-1, -1).
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2).
The node with value 20 occurs at position (1, -1).
The node with value 7 occurs at position (2, -2).
```

#### Example 2:
![](tree2.png)
```
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report [1,5,6], the node with value 5 comes first since 5 is smaller than 6.
```

### Constraints:

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 1000`
