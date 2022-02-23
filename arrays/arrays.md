Will write notes here if I think of something or want to remember something or if i'm just confused about something.

# array.cpp

Contains custom Unordered Array class. Lot's of things to do and also lot's of things to not to do.
Somehow it is a lot of fun to just write sometimes.

And sometimes it is more fun to not write and not do anything at all.

But the most fun is when I am doing what I am doing and not worrying about how something else might happen and what it would mean for different people and what that would mean for the same people if something else was to happen tomorrow or the weekend or at some other point or some other other point in life. What if no one wants to come to your funeral? Wouldn't you feel humilated for your kids and wife, even though you'd be dead?

Ahem. Sorry.

This file contains a custom Unordered Array class, exposing methods to add elements, remove elements, and other operations on elements in the array.
Also contains algorithms such as linear search, and now will add sort algorithms to it.

## Linear Search O(n)
- Just compare every value to search value.

## Bubble Sort O(n²)
- Compare first value with second, shift greater value to right. 
- Compare second to third, shift greater to right until rightmost element(n == number of elements) is maximum.
- Decrease upper bound by one, and recurse for rest of array. (sorted array of max values starts building up on right side of array).
- A comparison and swap is done on every step. 
- sorts right to left (but end up min to max)

## Selection Sort O(n²)
- go through array, keeping record of the min item seen so far
- swap min item to first position at end of loop
- increase lower bound by one and recurse, until whole array is traversed and sorted
- Same number of comparisons as Bubble Sort (O(n²)), but only one swap per round (O(n))
- sorts left to right (end up min to max)

## Insertion Sort O(n²)
- runs well on already partially or inserting an item in fully sorted list, can quit early
- if list is in reverse order (descending), is worst case, will need maximum comparisons and shifts, same performance as bubble sort.
- he best-case time is O(n × 1) = O(n) and the worst-case time is O(n × n) = O(n²)
- take i-1 item as sorted, go next item (which is now current item, i) and compare with prev 
- if prev is bigger, shift it to the right, and compare i with i-2, until 0th item is reached
- if i was smaller than all, shifted to 0th position
- if i was bigger at some point, break loop and insert there (shift all items from i coming down to the position)

## MergeSort O(n (log n))
- recursive function splits list into two halves
- halves split further until one item remains (in all lists?)
- then as functions return, the 1 item lists are sorted and merged into bigger lists
- second last step, we have two lists of half the values, then they are sorted and merged into the complete list.
- Need a temp array of equal size. Could be problematic if memory problems and list is very large.

## Shell Sort O(n (log n)²)
- Faster than the simpler sorts
- Slower generally than Quicksort, but faster on smaller sets of data
- Like an Insertions sort with multiple passes
- The initial passes have bigger gaps in between, data is sorted partially over the passes
- The final pass is like an insertion sort, with every element checked. The idea is that the earlier passes have prepared the data enough the final insertion sort step is fast.

## Quick Sort O(n (log n))
- in place, so no extra memory needed (except one variable for swap)

QuickSort()
{
    if (start >= end) return (c) 
    index = partition() (a.n + b) (looping through the list) (T(n))
    QuickSort(start, index-1) T(n/2)
    QuickSort(index+1, end) T(n/2)

    T(1) = c
    T = 2T(n/2) + c.n
    n( log n) average case
    n² worst case (if pivot is bad, and there is a full segment and 0 segment created from partitioning)
}

### Median of Three

### Randomized Partioning


### Partitioning O(n)
- Pivot value is value used as the condition in the partition (e.g. int value of 100)
- Pivot index marks the position in the container where the first section ends and second begins.
- start counter from left index, if find a value bigger than pivotvalue, start/resume counter from right index and then if find a value there, swap with left value. continue until indexes cross, which is the pivot index, return.


## Radix Sort O(n (log n))

Put elements into buckets/container according to some patter, then take them back from
buckets into the original container. After potentially multiple passes of doing so, data would be ordered according to the final putting back of elements from the organising containers. No comparison of value by value goes on. 

## Heap Sort  O (n log n)

- Heap is weakly ordered tree (can be implemented on top of array, lists, priority queue etc)
- weakly ordered, parent key is greater than child key
- so on removing elements from heap, we can expect them to be in ascending or descending order already
- insertion removal from heap is O(log n)
- sort is n log(n) because function has to run on each element, so times n (actually 2 x n, but is constant).



## Intro Sort


# orderedarray.cpp

- Contains custom Ordered Array class. Is already sorted through a push method, which uses a form of insertion sort (also modified to binary search insertion sort) to keep the array sorted as new elements are added.
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 
It has binary search available instead of linear search, which reduces complexity from O(n) to O(log n). 

And I'm sure probably some other functions etc for the array class.

## Binary Search O(log n)
- Start from the middle element of sorted array, and check if value matches
if not, choose one side of the array, discarding half members
recurs

# Arrays and STL Vectors

- If using custom classes or pointers, use vectors. Use them anyway. 

```
    SomeClass someArray[100]; calls a 100 constructors for 100 objects.

    vector<SomeClass> someVec;
    someVec.reserve(100); no constructors are executed to store.

```

- Vectors are containers/wrappers over dynamic arrays.
- Can be accessed with iterators as well as index based operations.
- Can be passed to functions expecting arrays etc ususally because of this..

