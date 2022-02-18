I was recently working on an algorithm problem about binary trees:

Consider a binary tree where every non-leaf node has exactly two children and all the leaf nodes are on the same level (called a perfect binary tree). Suppose we visit the nodes of the tree using post-order traversal. Given the height H, and a list of values L that represent values of nodes in the tree, return another list of values that are the parent nodes of the values in L.

I ended up drawing some examples of perfect binary trees by hand, and then visited nodes in a post-order way. I noticed three patterns:
  1) the left child of X always has a value of X - 2^(Y - 1), where Y is the level of the tree that the node is on (counting bottom-up)
  2) the right child always has a value of X - 1
  3) the root node always has the value (2^H) - 1, where H is the height of the tree

For example, a perfect binary tree of height 4 will have 15 as it's root node. Its left child = 15 - 2^(4 - 1) = 7 and its right child = 15 - 1 = 14.

The cool thing is we don't have to actually create the tree, we start at the value of the root node and calculate the value of current node's children and make our way down the tree. This ends up finding the solution in O(log(H) * n) time, where H is the height of the tree and n is the length of the list of values we're trying to find.

After coding up my solution in Python, I thought it would be fun to see how much faster the C implementation is. Each solution had to find the parent node value for every number from 1 to 1 million from a perfect binary tree with height 30.

Python: 8.33 seconds, C: 0.175 seconds.
