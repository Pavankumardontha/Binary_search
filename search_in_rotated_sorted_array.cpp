/*
In a rotated sorted array we have conditions 
1) if both target and mid belong to the first steep
a) if a[mid]> target => r = mid-1;
b) if a[mid]<target => l=mid+1
2) if target in first steep and mid in second steep => r = mid-1
3) if target in second steep and mid in first steep => l = mid+1
4) if target in second steep and mid in second steep 
a) if a[mid] > target => r = mid-1;
b) if a[mid] < target => l = mid+1;
*/
class Solution {
public:
    int search(vector<int>& a, int target) 
    {
        int n = a.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[mid]==target)
            return mid;
            else if(a[0]<=target and a[0]<=a[mid])
            {
                if(a[mid]>target)
                r=mid-1;
                else
                l=mid+1;
            }
            else if(a[0]<=target and a[mid]<=a[n-1])
            r=mid-1;
            else if(target<=a[n-1] and a[mid]>=a[0])
            l=mid+1;
            else
            {
                if(a[mid]>target)
                r=mid-1;
                else
                l=mid+1;
            }
        }
        return -1;
    }
};


// METHOD - 2 : IMPORTANT AND USED IN FURTHER PROBLEMS.
/*
At any given point in time [l,r] is either
1) sorted
- if sorted we can check if target lies inside [l,r] and move according. if not we can return -1
2) unsorted
- check if [l,mid] sorted or [mid,r] is sorted. See if the target belongs to the sorted part. 
If it belongs to the sorted part , move towards the sorted part. If not move towards the unsorted
part.
We check if the target belongs to the sorted part. If it belongs , we move to the sorted part. If not we move to the unsorted part.
*/

class Solution {
public:
    int search(vector<int>& a, int target) 
    {
        int n = a.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[mid]==target)
            {
                return mid;
            }
            else if(a[l]<=a[mid] and a[mid]<=a[r]) // [l,r] is sorted
            {
                if(a[l]<=target and target<=a[r]) // check if target belongs to the sorted part [l,r]
                {
                    if(target<a[mid])
                    r=mid-1;
                    else
                    l=mid+1;
                }
                else // target does not lie in [l,r]
                return -1; 
            }
            else if(a[l]<=a[mid] and a[mid]>a[r]) // left half [l,mid] is sorted
            {
                if(a[l]<=target and target<a[mid]) // check if target belongs to the sorted part [l,mid]
                r=mid-1;
                else
                l=mid+1;
            }
            else // right half [mid,r] is sorted
            {
                if(a[mid]<target and target<=a[r]) // check if target belongs to the sorted part [mid,r]
                l=mid+1;
                else
                r=mid-1;
            }
        }
        return -1;
    }
};


/* LATEST APPROACH WITH CLEAR EXPLAINATION */
class Solution {
public:
    bool check_if_sorted(vector<int> &nums, int l, int r)
    {
        if(nums[l]<=nums[r])
        return true;
        return false;
    }
    bool check_if_target_falls_between(vector<int> &nums, int target, int l, int r)
    {
        if(nums[l]<= target and target<=nums[r])
        return true;
        return false;
    }
    int binary_search(vector<int> &nums, int target, int l, int r)
    {
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            return mid;
            else if(nums[mid]<target)
            l=mid+1;
            else
            r=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) 
    {
        /*
        1) Always either one of subarray [l,mid] will be sorted or [mid,r] will be sorted if the array is rotated atleast once. If not rotated
        the total array will be sorted.
        2) The elements present in the left sorted array are always greater than the elements present in the right sorted array
        [4,5,6,7,0,1,2]
        [0,1,2,3,4,5,6]
        1) l=0 r=6 m=3 -> [l,m] is sorted but target does not belong to this so l=m+1
        2) l=4 r=6 m=5 -> [l,r] is sorted and target belongs to this array. Apply binary search here.
        */
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            return mid;
            else if(check_if_sorted(nums,l,mid)) // check if [l,mid] is sorted
            {
                // check if target falls between [l,mid]. if it falls , apply binary search
                if(check_if_target_falls_between(nums,target,l,mid))
                {
                    // apply binary search on [l.mid] searching for target
                    return binary_search(nums,target,l,mid);
                }
                else
                l=mid+1; // if the target does not fall between [l,mid[ then just move to the right
            }
            else
            {
                // [mid,r] is sorted
                if(check_if_target_falls_between(nums,target,mid,r))
                {
                    //apply binary search on [r,mid] searching for target
                    return binary_search(nums,target,mid,r);
                }
                else
                r=mid-1; // if the target does not fall between [mid,r] then just move to the left
            }
        }
        return -1;
    }
};
