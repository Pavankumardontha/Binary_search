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

class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int n = a.size();
        int l=0;
        int r=n-1;
        if(n==1)
        return 0;
        while(l<=r)
        {
            int mid =  l + (r-l)/2;
            if(mid==0)
            {
                if(a[mid]>a[mid+1])
                return mid;
                else
                l=mid+1;
            }
            else if(mid==n-1)
            {
                if(a[mid]>a[mid-1])
                return mid;
                else
                r=mid-1;
            }
            else
            {
                if(a[mid]>a[mid-1] and a[mid]>a[mid+1])
                return mid;
                else if(a[mid]<a[mid+1])
                l=mid+1;
                else
                r=mid-1;
            }
        }
        return -1;
    }
};


/* APPROACH - 2 */ 
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        /*Here we will check the neighbouring elements. So its better to check the edge cases first of the starting and ending elements.*/
        int n = nums.size();
        if(n==1)
        return 0;
        if(nums[0] > nums[1])
        return 0;
        if(nums[n-1] > nums[n-2])
        return n-1;
        // since we have already checked for the first and the last elements being peak, we can remove them from our range
        int l = 1;
        int r = n-2;
        int mid;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            /* 
            We always move in the increasing direction !! 
            We will have 3 possible cases here out of (mid-1,mid,mid+1)
            1) nums[mid] is the greatest in (mid-1,mid,mid+1) -> return mid since we got the peak element index here.
            2) nums[mid-1] is the greatest in (mid-1,mid,mid+1) -> we move towards mid-1 to the left -> move the right pointer to left
            3) nums[mid+1] is the greatest in (mid-1,mid,mid+1) -> we move towards mid+1 to the right -> move the left pointer to the right
            */
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
            return mid;
            else if(nums[mid]<nums[mid-1] and nums[mid-1]>nums[mid+1])
            r=mid-1;
            else
            l=mid+1;
        }
        return -1;
    }
};



