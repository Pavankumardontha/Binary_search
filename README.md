# Binary_search
1) Standard binary search
2) Find first and last with given property
3) Find target indices after sorting array
4) First bad version
5) Search insert position (leetcode)
6) Two Sum - 2 (this is done using 2 pointer approach and not binary search)
7) Row with max 1s (coding ninjas)
8) find square root of a number using binary search (leetcode)
9) Search in 2D matrix (leetcode)
10) Search in 2D matrix - 2 (leetcode)
11) Search in rotated sorted array (leetcode)
12) Search in rotated sorted array - 2 (leetcode)
13) Find minimum in rotated sorted array (leetcode)
14) Find minimum in rotated sorted array - 2 (leetcode)
15) Single element in sorted array (leetcode)
16) Kth missing positive number (leetcode)
17) Koko eating bananas (leetcode)
18) Minimum Number of Days to Make m Bouquets (leetcode)
19) Capacity to ship packages within D days (leetcode)
20) Minimized Maximum of products distributed to any stores (leetcode)
21) Aggressive cows (SPOJ)
22) Allocate minimum no. of pages (GFG)
23) Painters partition problem - 2 (GFG)
24) Find peak element in an array (leecode)
25) Find peak element - 2 (leetcode)
26) Peak Index in a Mountain array. (leetcode)
27) Find in mountain array. (leetcode) : find the peak index in the mountain array and then apply BS on [0,peak_ind] and [peak_ind,n-1] range to find the target.
28) Find the median of 2 sorted arrays.
29) Find the kth element of the 2 sorted arrays.
30) Sum of middle elements of 2 sorted arrays(gfg)
31) Find median in a data stream : Use max heap to store the first half of the sorted array and min heap to store the second half of the sorted array. If both min heap and max heap sizes are equal then we can use the top elements to find the median. if not ans will be the top of the max heap.
32) Median in row wise sorted matrix (gfg) : Find the minimum element from the first column and the maximum from the last column. Apply binary search on range [minimum,maximum]. In each binary search , find the no. of elements which are less than or equal to mid(n1) and the no. of elements which are greater than or equal to mid element(n2) in the entire matricx. Check if n1>=(n*n+1)/2 and n2>=(n*n+1)/2. Note that since the matrix is
of odd order , only middle element is required to calculate the median.
