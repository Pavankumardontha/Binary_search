/*
We will do everything same linke binary search. We will calculate the middle element
and test for the peak element property. But before testing for the property of peak 
element , we will have some edge cases that we need to deal with
a) if we have only one element in our array,there will not be any mid-1 element and 
mid+1 element to access. We should return 0 directly here.
b) if mid==0 then there will be no mid-1 element.Only mid+1 element will be present
c) if mid==n-1 then there will be no mid+1 element. Only mid-1 element will be present
d) if mid>0 and mid<n-1 then we will have both mid+1 and mid-1 elements to compare

In each of the cases apart from a) we have a possibility of getting answer. So in each 
step we need to check for answer

What we are essentially doing is going in the direction of the rising slope(by choosing the element which is greater than current). How does that 
guarantee the result? Think about it, there are 2 possibilities.a) rising slope has to keep rising till end of the array b) rising slope will encounter 
a lesser element and go down.In both scenarios, we will have an answer. In 
a) the answer is the end element because we take the boundary as -INFINITY 
b) the answer is the largest element before the slope falls. 
*/

int solve(vector<int> &a , int left, int right)
{
    if(a.size()==1)
    {
        /*
        Note that if we have only one element in our array, then mid==0 and also 
        mid = a.size()-1 at the same time. There will not be any mid-1 element and 
        mid+1 element to access. Care should be taken of this edge case.
        */
        return 0;
    }
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(mid>0 and mid<a.size()-1)
        {
            // both mid-1 and mid+1 indices will exist
            if(a[mid-1]<a[mid] and a[mid]>a[mid+1])
            return mid;
            else if(a[mid-1]>a[mid])
            right = mid-1;
            else
            left = mid+1;
        }
        else if(mid==0)
        {
            if(a[mid]>a[mid+1])
            return mid;
            else
            {
                //a[mid] <= a[mid+1]
                left = mid+1;
            }
        }
        else 
        {
            if(a[mid]>a[mid-1])
            return mid;
            else
            {
                //a[mid]<a[mid-1]
                right = mid-1;
            }
        }
    }
    return -1;
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        return solve(nums,0,nums.size()-1);
    }
};
