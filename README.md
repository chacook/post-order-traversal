I was recently working on an algorithm problem about binary trees:

Consider a binary tree where every non-leaf node has exactly two children and all the leaf nodes are on the same level (called a perfect binary tree). Suppose we visit the nodes of the tree using post-order traversal. 

The problem is: Given the height of the tree H, and a list of values L that represent values of nodes in the tree, return another list of values that are the parent nodes of the values in L.

I ended up drawing some examples of perfect binary trees by hand, and then visited nodes in a post-order way. I noticed three patterns:
  1) the left child of a node X always has a value of X - 2^(Y - 1), where Y is the level of the tree that the node is on (counting bottom-up)
  2) the right child of a node X always has a value of X - 1
  3) the root node always has the value (2^H) - 1, where H is the height of the tree

For example, a perfect binary tree of height 4 will have 15 as its root node. Its left child = 15 - 2^(4 - 1) = 7 and its right child = 15 - 1 = 14. Node 7 is on level 3 of the tree, so it will have a left child = 7 - 2^(3 - 1) = 3 and a right child = 7 - 1 = 6.

The cool thing is we don't have to actually create the tree, we can just start at the value of the root node and calculate the values of the current node's children, decide whether to go left or right, and repeat. This ends up finding the solution in O(n * log(H)) time, where n is the length of the list of values we're trying to find and H is the height of the tree.

After coding up my solution in Python, I thought it would be fun to see how much faster the C implementation is. For my benchmark, each solution had to find the parent node value for every number from 1 to 1 million from a perfect binary tree of height 30.

Python: 8.33 seconds, C: 0.175 seconds.
