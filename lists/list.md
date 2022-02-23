# Linked Lists
- Elements of a linked lists are connected by pointers.
- These can be allocated at any time, so data can be appended any time easily,
not just at initialisation. (arrays have to be expanded for new data outside init range)
- But elements are probably not allocated next to each other, so random access not possible, cannot be accessed by index. (So access is slower than arrays)
- Linked List is normally made up of node(struct or object containing data member and self referencing (to type) pointer ), iterator and list itself.
- 

## Types

### Singly Linked lists
- iterator, node and linked list
- node is not directly used, part of linked list
    - when initialising or adding an object to list
    - we create a node, and get a pointer to this node. (Can also directly use the node but pointers are natural for most linked list things)
    - data added to node, and next pointer updated to fit into list
- Iterator is a node, which uses its next field to traverse list
- List has root and lastNode pointer. (which are actually nodes that are part of list)
    - if both NULL, means list is empty
    - if one item, it will be both root and lastNode
- Can also use just a node instead of custom iterator, but have to make member fields of linkedlist and linknode public then.

```
   cout << "Contents of Linked List without custom iterator: ";
    //have to make member fields of classes public for this:
    
    LinkNode<int> *it = lList.m_root;

    while (it != NULL){
        cout << " " << it->m_data;
        it = it->m_next;
    }

    cout << "." << endl;

```

### Double Ended Linked Lists
- Allows inserting and removing from both ends of lists

### Doubly Linked Lists
- Allows traversal from root forward as well as from lastNode backwards.
- custom iterator to add suport for backwards traversal.

### Cicular Lists
- last node's next is root node, root node's prev is last node (if double linked list)

### STL list container <list>
- Doubly linked, double ended list
- Is also actually a circular list. (Iterator implementation starts from the last node and has an internal link to the root node. Bit weird but ok must be good or something)
- sort function runs in O(N * log(N))
- preferable to call empty() to test if a container is empty instead of testing
the return value of size(). (True for all STL containers)

### Lists vs Arrays
| Lists | Arrays |
|-------|--------|
| Fast insertion, deletion at ends of list | Array must be shifted or reallocated |
| Can expand and shrink in almost constant time | More expensive to expand, shrink |
| Slow to search for particular value | Faster search algos |
| Do not have random access | Random access for any index |
| Data + Pointer in node, extra memory | Just Data, less memory |
| However, overall memory allocated is according to n actual elements (so easier and maybe more efficient on adding extra items at runtime) | arrays usually allocated in blocks with unneeded memory buffer |

## Stacks, Queues, Double-ended Queues and Priority Queues

- Adapters built on top of arrays, lists, other data structures
- created for specific task and then usually discarded

### Stack

- e.g. Program stack
- O(1)
- LIFO
- only one item inserted or removed at a time
- no random access, to acess middle elements, top ones must be popped
- 

### Queue, Dequeue

- e.g. message queues
- O(1)
- FIFO
- Link List better underlying structure for Stacks, Queues, because
    we need fast expansion, insertion and removal at ends. Don't need
    random access or searching or insertion in middle somewhere.

### Priority Quees

- Insertion depends on O(n), other operations O(1).
- Implmented as Tree in STL so insertion is faster