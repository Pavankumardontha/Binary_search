

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

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(target==nums[mid])
            return mid;
            
            // if mid falls in left sorted portion
            if(nums[l]<=nums[mid])
            {
                // we will use left and mid index as a basis to decide which side to go
                if (target > nums[mid] or target < nums[l])
                l = mid + 1;
                else
                r = mid - 1;
            }
            else
            {
                // if mid falls in right sorted array
                // we use right and mid index as a basis to decide which side to go.
                if( target < nums[mid] or target > nums[r])
                r = mid - 1;
                else
                l = mid + 1;
            }
        }
        return -1;
    }
};
