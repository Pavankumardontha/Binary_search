bool property(int x)
{
	/* find the first element which is greater than equal to 20 */
	return x>=20;
}



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
