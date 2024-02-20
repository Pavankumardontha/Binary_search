#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool property(int x)
{
	/* find the first element which is greater than equal to 20 */
	return x>=20;
}

/*

CASE - 1:
Before moving forward let us decribe the problem. Lets say we have a property which looks like 
F,F,F,T,T,T,T applied on the array elements. 
0,1,2,3,4,5,6

In the above case , we want to find the first index which is True and here the answer is index 3 in the above case. By finding this index we can also find
the last false index which is one less than the first true index 
last false index = first true index - 1

CASE - 2:
Similarly , in some of the cases, the property if applied on an array might look like this 
T,T,T,F,F,F,F 
0,1,2,3,4,5,6

In the above case, we want to find the last index which is true and here the answer is index 2. By finding this index , we can also find the first false 
index which is one more than the last true index. 
first false index = last true index + 1

CASE - 3:
In this case we somewhat have a different scenario like 
F F F F T T T F F F F F
OR 
T T T T F F F T T T T T

Ex : find the first and last index of a target element in the sorted array [1,2,2,2,2,4,5,6,7,7,7]. 
If the target element is 2 , the answer is [1,4]. So for these kind of problems also we use binary search. 
*/



// APPROACH-1 
// [T,T,T,F,F,F,F]
int first_false(vector<bool> a)
{
    int n = a.size();
    int l = 0;
    int r =n-1;
    int index = -1;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        if(property(a,mid)==false)
        {
            index = mid;
            r = mid-1;
        }
        else
        l = mid+1;
    }
    return index;
}

// [F,F,F,F,T,T]
int first_true(vector<bool> a)
{
    int n = a.size();
    int l = 0;
    int r = n-1;
    int index = -1;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        if(property(a,mid)==true)
        {
            index = mid;
            r = mid-1;
        }
        else
        l = mid+1;
    }
    return index;
}

// [F,F,F,F,T,T,T]
int last_false(vector<bool> a)
{
    int n = a.size();
    int l = 0;
    int r = n-1;
    int index = -1;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        if(property(a,mid)==false)
        {
            index = mid;
            l = mid+1;
        }
        else
        r = mid-1;
    }
    return index;
}

// [T,T,T,F,F,F,]
int last_true(vector<bool> a)
{
    int n = a.size();
    int l = 0;
    int r = n-1;
    int index = -1;
    while(l<=r)
    {
        int mid =  l + (r-l)/2;
        if(property(a,mid)==true)
        {
            index = mid;
            l = mid+1;
        }
        else
        r = mid-1;
    }
    return index;
}

//--------------------------------//


// APPROACH-1
int first_element_with_property()
{
	
	/*it can also be possible that there are no elements with this property then in that case we should return -1.
	If last element is not satisfying the property then no element will satisfy the given property.There will be one index in the array
	from which all the elements greater than this index will satisfy the property.So for a solution to exist,the last element should 
	satisfy the property.
	find the first index that is true in F,F,T,T,T,T ?? we will implement below code such that it is similar to finding the last element with
	some property.
	 */
	int left = 0;
        int right = n-1;
        int first_index = -1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(property(mid))
            {
                first_index = mid;
                right = mid-1;
            }
            else
            left = mid + 1;
        }
        return first_index; // returns -1 if no element satisfying property is found	
}

int last_element_with_propert()
{
	/* find the last index that is true in T,T,T,T,F,F,F ?? find the index of first false instead and return index - 1. */
	int left=0;
	int right=n-1;
	int last_index = -1;
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		if(property(mid)) 
		{
			last_index = mid;
			left=mid+1;
		}
		else
		right=mid-1;
	}
	return last_index;//returns -1 if no such elements exist.
}


int find_first_index(vector<int> & a, int target)
{
	// a = [1,2,2,2,2,4,5,5,5,6] -> if target = 2 this functions returns index 1 which is the first occurence index of target=2.
    	int n = a.size();
    	int left = 0;
    	int right = n-1;
    	int first_index = -1; 
    	while(left<=right)
    	{
        	int mid = left + (right-left)/2;
        	if(a[mid]<target)
        	left = mid + 1;
        	else 
        	{
            		/*we store the mid and reduce the search space by moving right index since we want the 
            		first occurence index. We do the reverse ie move the left index if we want the last index
            		occurence.*/
            		if(a[mid]==target)
            		first_index = mid;
            		right = mid-1;
        	}
    	}
    	return first_index;
}

int find_last_index(vector<int> &a, int target)
{
	// a = [1,2,2,2,2,4,5,5,5,6] -> if target = 2 this functions returns index 4 which is the last occurence index of target=2.
    	int n = a.size();
    	int left = 0;
    	int right = n-1;
    	int last_index = -1;
    	while(left<=right)
    	{
        	int mid = left + (right-left)/2;
        	if(a[mid]>target)
        	right = mid-1;
        	else
        	{
            		if(a[mid]==target)
            		last_index = mid;
            		left = mid+1;
        	}
    	}
    	return last_index;
}

