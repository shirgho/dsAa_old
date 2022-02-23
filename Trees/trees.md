# Trees

Data structure that forms some kind of meaningful hierarchy on a set of Data.

Start off with a node that is called the root.
Nodes in trees are connected by edges. (C++: abstract, represented by pointers that connect to other nodes). (Could also be represented by array index)

The nodes of a linked list are kinda like a tree, each connected by a one-directional edge that is represented by the next pointer. The pointers have no special meaning other than acting as links. In trees, the links or edges signify some relationship.

A tree itself is a type of graph.

## Traversal

### BFS or Level Order Traversal
More in graphs
### Depth First Searches
-- preorder: node, left, right
    - 
-- postorder: left, right, node
    - used to delete a tree e.g. because child nodes visited first
-- inorder: left, node, right

## General Trees
- Root, children, siblings, Parents
- Not so fast for searches etc

## Binary Trees
- Two child nodes max, left and right
- fast insertions, deletions and searching
- keys play important role:
    - if key of node is higher than root, new node is placed on right, otherwise as left child
    - if a child already exists, new node is allocated to right or left of child
- the larger the tree, n, the more efficient some algorithsm:
    - in ordered array of 1000k items, would need on average 500k comparisons to find position of object. In binary Tree, would need max 20 comparisons.
    - C = log(N-1)
        - depends on if tree is balanced or not (has on average equal number of left and right child nodes)
        - worst case unbalanced is when nodes inserted in ascending or descending order, which results in a completely one sided tree, or a list.
- the order in which nodes are inserted decides if a tree is balanced or unbalanced and how unbalanced

## kd-trees
- k dimensional tree, keys have multiple (k) dimensions
- range searches, nearest neighbor searches, space partitioning etc
- kd tree with one dimension == binary tree

## B-trees
- balanced tree, multiple child nodes can be attached to one node according to predefined range.
- if node violates range, tree is reordered by joining nodes together or splitting them.
- waste maybe more space but do not need to be rebalanced as often
- kept balanced by keeping all lead nodes on same depth
- more complicated to implement, used in databases etc

### 2-3 trees
- b-trees of order 3 (can have upto 3 child nodes for each node)
- a node with data item can have two children, a node with two data items can have 3 children. 
- self balancing tree, ordered tree

### 2-3-4 trees
- order of 4 (4 child nodes up to)
- harder to implement than black-red tree but considered equivilant, isomorphic.

## BSP tree

## AVL trees
- self balancing binary search tree (2 child nodes for every node)
- heights? of child nodes differ most by one
    - height value or balance factor : value of adding up all child node keys on both sides (left and right). Difference between these two totals should be 1,0,-1, or else tree is not balanced.
    - balance factor of a node is the height of the right child minus the hight of the left child of any given node. If between -1 and 1, node is balanced.
- tree rotations used to keep tree balanced when isnerting deleting nodes

## Red-black trees
- balanced binary trees.
- more complicated than a binary tree but easier than most b-trees
- insertion and deletions are different, top down or bottom up, alter structure of tree to keep it balanced.

## Heaps
- weakly ordered binary tree
- completely silled from left to right without gaps
- every node in heap is larger than or euqual to its child nodes

- purpose usually to allow fast removal from top of heap (getting the max value repeatedly)


- keeps node with largest key as root key, on top of tree (depending on order condition)
- all nodes within are not necessarily in order, unlike binary trees.
    - just that child nodes keys are lesser than root node key.
- STL priority queue uses heap as underlying data structure.
- cannot use binary search algorithm as for other trees because weakly ordered.
- Heaps themselves often implemented as arrays with non linear expansion size when memory is not critical.

- PriorityQueues by default are similar/maintain structure of Max Heap. 
-- PriorityQueue implemented using heap