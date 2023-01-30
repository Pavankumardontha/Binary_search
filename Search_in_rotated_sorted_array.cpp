

/*
There are 2 sorted arrays . 
We will first calculate the mid element and see if that is equal to target or not. If it is then we stop the iteration if not 
we have 2 cases to deal with 
Mid index can either fall either in first sorted array or second sorted array.
1) if mid falls in first sorted array. possible if nums[l] <= nums[mid]
  - if target > nums[mid] or targest < nums[l] then we need to search in the right half so left = mid + 1;
  - else right = mid - 1;
2) if mid element falls in the right sorted array. 
  - if target < nums[mid] or target > nums[r] we will search in the left half and so r = mid - 1
  - else left = mid + 1
  
*/

int solve(vector<int>& a,int target)
{
    int left = 0;
    int right = a.size()-1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(a[mid]==target)
        return mid;
        else if(a[left]<=a[mid])
        {
            //mid falls in first sorted array
            if(a[left]<=target and target<a[mid])
            {
                // target falls in [left,mid-1]
                right = mid-1;
            }
            else
            left = mid+1; // target falls in [mid+1,right]
        }
        else
        {
            // mid falls in second sorted array
            if(a[mid]<target and target<=a[right])
            {
                // target falls in [mid+1,right]
                left = mid+1;
            }
            else
            right = mid-1; // target falls in [left,mid-1]

        }
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        return solve(nums,target);
    }
};
