# Hash tables

Also called dictionaries, maps etc.

A hashing function/algorithm is used on an object to get it's key, which is
an index that fits in the range of the array or whatever is used to implement
the hash table. This index is then looked up to store/access the object.

'''

int HashFunction(string &str)
{
    int hash = 0;

    for(int i=0; i < (int)str.size(); i++){
        int val = (int(str[i]));
        hash = (hash * 256 + val) % m_size;
    }

    return hash;
}

A problem with hashtables is collisions on the hash function i.e. when two different objects are hashed to the same index value. This can be solved with

The ratio of the total number of items to the hash table's size is knows as the load factor.

## Open Addressing
Linear probing, quadratic probing:
Inserting the object in the next free spaces. Results in primary and secondary clusters. (groups of same hashed objects)

Double Hashing:
Using a second hash function to find the actual index after collision.
HERE the array size should be a prime number, to avoid hash values looping
through indexes with no change.

## Seperate Chaining

When there is collision on an index, a link list is set up on the index to
collect nodes there. When searching, the object is searched for on the index and then through the index's linked list.

## STL-compatible containers

Assosiate containers. 
- Type of objects to be stored must be declared.
- Hashing function
- Comparison function
- Optionally allocator

boost:

### hash_set, hash_multiset

### hash_map, hash_multimap

std:

### unordered_set, unordered_multiset
- sorted by key in a list like structure.
- key is the value, element, not like map where it's a pair
- keys cannot be changed, must be deleted and new inserted
- Insertions, lookups, removals : O(log N)
### set, multiset

### unordered_map, unordered_multimap
- insertion, removal, access generally O(1)

### map, multimap
- ordered sequence of key-value pairs.
- implemented as balanced tree structure, so possible to maintain order by specific tree traversal (not sure actually baout c++ but in java)

### Remove-Erase
https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom

