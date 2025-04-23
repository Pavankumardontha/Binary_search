/*
Same like previous case with one extra handling when a[l]==a[mid]==a[r] in which case we move in 
both the directions by 1.
*/

class Solution {
public:
    int findMin(vector<int>& a) 
    {
        int n = a.size();
        int l = 0;
        int r = n-1;
        int minimum = a[0];
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[l]==a[mid] and a[mid]==a[r])
            {
                minimum = min(minimum,a[l]);
                l++;
                r--;
            }
            else if(a[l]<=a[mid] and a[mid]<a[r])
            {
                // [l,r] is sorted
                minimum = min(minimum,a[l]);
                return minimum;
            }
            else if(a[l]<=a[mid] and a[mid]>a[r])
            {
                // [l,mid] is sorted
                minimum = min(minimum,a[l]);
                l=mid+1;
            }
            else
            {
                // [mid,r] is sorted
                minimum = min(minimum,a[mid]);
                r=mid-1;
            }
        }
        return minimum;
    }
};


/* Approach-2 : Same like search in rotated matrix - 2 */
class Solution {
public:
    bool check_if_sorted(vector<int> &nums, int l, int r)
    {
        if(nums[l]<=nums[r])
        return true;
        return false;
    }
    int findMin(vector<int>& nums) 
    {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = INT_MAX;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[l] == nums[mid] and nums[mid]==nums[r])
            {
                /* same like search in rotated matrix-2 only this condition comes up extra to eliminate duplicates */
                ans = min(ans,nums[l]);
                l++;
                r--;
            }
            else if(check_if_sorted(nums,l,mid))
            {
                ans = min(ans,nums[l]);
                l=mid+1;
            }
            else
            {
                ans = min(ans,nums[mid]);
                r=mid-1;
            }            
        }
        return ans;
    }
};










