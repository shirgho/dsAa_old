# Graphs

- Relationship of each node is more abstract in a graph than a tree. (Not just parent children)
- Nodes are called Vertices.
- Vertices that are connected are adjacent vertices.
- no keys in graphs
- edges can go one way ( directed)  or both ways (non directed)
- edges of graph often represented by adjacency matrix or adjacency list. Trees use references to objects or array indexes.
- vertices can be weighted/unweighted
- Vertices can have different number of adjacent vertices (unlike binary tree)
- Connected graph:there is a path from all vertices to all other vertices, directly or indirectly.
    - path is a sequence of edges that can be taken to get to a destination vertex from a starting vertex.

## Searching

- In ordered Tree or Graph, like BST, easy to search for value.
- In unordered, have optioins like DFS and BFS

## Depth First Search

- Also in Trees (inorder, preorder, postorder)
- stack data structure (in iterative version)
- push starting vertex to stack and mark as checked
- if not destination, select first adjacent vertex from start vertex
- repeat until destination found or not
- if yes, elements in stack are the vertices making up the path
- if no, pop recent vertice from stack, and select another adjacent vertice
- repeat until destination fround or all vertices marked( which means no path possible)
- simulations of games (chess engines)


- Family Tree example: Searching for living person, would be nearer the bottom of the tree. DFS would go lower levels faster than BFS.

## Breadth First Search

- Queue in the iterative version
- something like Level Order Tree Traversal
- used to find shortest path to a target vertex
    - p2p network, gps systems, social networking sites

- Start at root note
- then scan each node in the first level starting from leftmost node to right
- continue to next level etc, until node found or all nodes scanned

- When traversing one level, need some way of knowing which nodes to traverse when get to next level
- This is done by storing pointers to child nodes when traversing a level
- BFS can potentially use a lot of memory because of this storing of pointers

- Family Tree example: Searching for an old ancestor, who is dead, would be nearer the top of the tree

## Minimal Spanning Tree

- find the minimum number of connected edges needed to visit every vertex
- can be many different valid paths
- unweighted graph
    - the minimal spanning tree in an unweighted graph find the first minimal spanning tree out of many different possibilities.
- weighted graph 
    - finds the msp with the least weights (shortest path)
        - 1.first vertex is current vertex and checked flag
        - 2.loop while number of checked vertices does not equal total vertices
        - 3.add all unchecked adjacent vertices and weights to priority queue
        - 4.if pq empty after last step, graph has cycle
        - 5.remove edge with lowest weight and add to list that makes msp
        - repeat 2 through 5 till 2 breaks

## Topological Sort

- In a directed graph, to get an order of correct traversal
- like minimal spanning tree, can have more than one correct solution, returns first
- must not be a cyclical graph ( a tree e.g. is not cyclical)
- if number of edges greater or equal to vertices, then is cyclical graph
- otherwise called directed acyclic graph
- works on both connected and nonconnected directed graphs

### implement
- find a vertex with no successor
    - easy using adjacency matrix
    - the row index of a row with all columns equal to 0 is the index for vertex with no successor.
- delete from graph, add to stack
- repeat 1 and 2 until graph empty
- no stack has topological order

## A* Algorithm
- finding paths based on weight, object avoidance etc
- optimised, solved dynamically by frame, instead of all at once for performace

## Dijkstra's algorithm
- Edsger Dijkstra 