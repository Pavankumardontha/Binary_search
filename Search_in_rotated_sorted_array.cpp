
/*
There are 2 sorted arrays . 
Mid index can either fall either in first sorted array or second sorted array. In each case we have 3 cases to deal with 
1) first sorted array.
  - a[target] == a[mid] : return the index
  - a[target] < a[mid] : we need to decide whether we have to search left half or right half.
  - a[target] > a[mid] : we need to decide whether we have to search left half or right half.
2) second sorted array
  - a[target] == a[mid] : return the index
  - a[target] < a[mid]
  - a[target] > a[mid]
*/
