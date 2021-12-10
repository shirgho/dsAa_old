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
- if list is in reverse order (descending), is worst case, will need maximum comparisons and shifts, same
performance as bubble sort.
- take i-1 item as sorted, go next item (which is now current item, i) and compare with prev 
- if prev is bigger, shift it to the right, and compare i with i-2, until 0th item is reached
- if i was smaller than all, shifted to 0th position
- if i was bigger at some point, break loop and insert there (shift all items from i coming down to the position)

# orderedarray.cpp

Contains custom Ordered Array class. Is already sorted through a push method, which uses a form of insertion sort (also modified to binary search insertion sort) to keep the array sorted as new elements are added.

It has binary search available instead of linear search, which reduces complexity from O(n) to O(log n). 

And I'm sure probably some other functions etc for the array class.

## Binary Search O(log n)
Start from the middle element of sorted array, and check if value matches
if not, choose one side of the array, discarding half members
recurs
