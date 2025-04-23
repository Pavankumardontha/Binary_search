/*
Here there might be a problem where a[l] = a[r] = a[mid] in this case , we will not be able 
to know whether [l,r] ,[l,mid] and [mid,r] is sorted or not. So we will not know in which direction to move either to the left or to the right. 
In this case , we will move to the left and as well to the right by 1, ie l++ and r--;
Apart from this , everything is same as the previous case with distinct elements.
*/
class Solution {
public:
    bool search(vector<int>& a, int target) 
    {
        int n = a.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[mid]==target)
            return true;
            else if(a[l]==a[r] and a[l]==a[mid])
            {
                l++;
                r--;
            }
            else if(a[l]<=a[mid] and a[mid]<=a[r]) // [l,r] is sorted
            {
                //target lies in [a[l],a[r]]
                if(a[l]<=target and target<=a[r])
                {
                    if(a[mid]>target)
                    r=mid-1;
                    else
                    l=mid+1;
                }
                else // target does not lie in [a[l],a[r]]
                return false;
            }
            else
            {
                //[l,r] is not sorted -> this means either [l,mid] is sorted or [mid,r] is sorted
                if(a[l]<=a[mid]) // [l,mid] is sorted
                {
                    if(a[l]<=target and target<a[mid]) // check if target belongs to the sorted part
                    r=mid-1;
                    else
                    l=mid+1;
                }
                else
                {
                    //[mid,r] is sorted
                    if(a[mid]<target and target<=a[r]) // check if target belongs to the sorted part
                    l=mid+1;
                    else
                    r=mid-1;
                }
            }
        }
        return false;
    }
};



/* Approach - 2 Same approach but written more cleanly */
class Solution {
public:
    bool binary_search(vector<int> &nums, int target, int l, int r)
    {
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            return true;
            else if(nums[mid]>target)
            r=mid-1;
            else
            l=mid+1;
        }
        return false;
    }
    bool check_if_target_falls_between(vector<int> nums,int target, int l, int r)
    {
        if(nums[l]<=target and target<=nums[r])
        return true;
        return false;
    }
    bool check_if_sorted(vector<int> nums, int l, int r)
    {
        if(nums[l]<=nums[r])
        return true;
        return false;
    }
    bool search(vector<int>& nums, int target) 
    {
        /*
        the only case which we need to handle here in case of duplicate elements is when 
        a[l] == a[mid] == a[r] In this case , we will not know in which direction we need to move.
        In this case we just shrink the search space by 2 (l++ and r--).
        */
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            return true;
            else if(nums[l] == nums[mid] and nums[mid]==nums[r])
            {
                // this is the only extra condition
                l++;
                r--;
            }
            else if(check_if_sorted(nums,l,mid))
            {
                //[l,mid] is sorted 
                if(check_if_target_falls_between(nums,target,l,mid))
                {
                    return binary_search(nums,target,l,mid);
                }
                else
                l=mid+1;
            }
            else
            {
                // [mid,r] is sorted
                if(check_if_target_falls_between(nums,target,mid,r))
                {
                    return binary_search(nums,target,mid,r);
                }
                else
                r=mid-1;
            }
        }
        return false;
    }
};


