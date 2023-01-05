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



int first_element_with_property()
{
	
	/*it can also be possible that there are no elements with this property then in that case we should return -1.
	If last element is not satisfying the property then no element will satisfy the given property.There will be one index in the array
	from which all the elements greater than this index will satisfy the property.So for a solution to exist,the last element should 
	satisfy the property.
	find the first index that is true in F,F,T,T,T,T ?? we will implement below code such that it is similar to finding the last element with
	some property.
	 */
	int left=0;
	int right=n;//note here that right is not n-1 which is in traditional binary search.
	while(left<right) //note the change here with the normal binary search code.
	{
		int mid=left+(right-left)/2;
		if(property(mid)) //if middle element is true
		right=mid;
		else
		left=mid+1;//if the middle element is false
	}
	return left;//returns n if no such elements exist.we can also return right since both left and right are equal in this case.
	
/*the loop exists when left == right. If no elements exists,then always only the left index will move towards the right and at the end both left
becomes equal to the right which was initially n.*/
	
}

int last_element_with_propert()
{
	/* find the last index that is true in T,T,T,T,F,F,F ?? find the index of first false instead and return index - 1. */
	
	int left=0;
	int right=n;//note that here also it is n.
	while(left<right)
	{
		int mid=left+(right-left)/2;
		if(!property(mid)) //if the middle element is false
		right=mid;
		else
		left=mid+1;
	}
	return left-1;//returns -1 if no such elements exist.we can also return right-1 since both left and right are equal.
/* if no element has the property,then in that case, only right gets updated and moves towards the left.Left is initially at 0 and thus atlast
right also becomes equal to left ie 0.In this case,there is no last element with a given property.hence left - 1 becomes -1.

/*lets we have an array like T F F F F F F F F then in this case,only the first element is satisfying the property and it also is the last 
element with the property.So in the final iteration:
left = 0;
right = 1;
now, mid = 0 and p(a[mid]) is true and hence in this case left becomes 1 and equals to right and hence the loop breaks.We return left-1 which 
is 0 in this case and its the obvious answer which we have expected.*/

}
