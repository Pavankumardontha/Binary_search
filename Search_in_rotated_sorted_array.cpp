/*
Initially , there are 2 sorted arrays. Left sorted array and the right sorted array.
1) calculate mid and check if its equal to the target. If it is equal to target then return the index or 
2) our [left,right] can either be sorted or not sorted.
a) if it is sorted then we will apply simple binary search and move the left and right pointers accordingly.
b) if [left,right] is not sorted then, [left,mid] or [mid,right] might be sorted. Either one of the arrays might be sorted and not both of them at the same
time. Check if [left,mid] or [mid,right] is sorted and apply binary search only on the sorted part of the array.
*/
class Solution {
public:
    int search(vector<int>& a, int target) 
    {
        int left = 0;
        int right = a.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(a[mid]==target)
            return mid;
            else if(a[left]<=a[mid] and a[mid]<=a[right])
            {
                //[left,right] is sorted
                if(target<a[mid])
                right = mid-1;
                else
                left = mid + 1;
            }
            else
            {
                /*
                [left,right] is not sorted. So either [left,mid] might be sorted or [mid,right] might be sorted
                In other words , mid can fall either in the right sorted array or left sorted array*/
                if(a[left]<=a[mid] and a[mid]>=a[right])
                {
                    // [left,mid] is sorted
                    if(a[left]<=target and target<a[mid])
                    right=mid-1;
                    else
                    left = mid+1;
                }
                else
                {
                    //[mid,right] is sorted
                    if(a[mid]<=target and target<=a[right])
                    left = mid+1;
                    else
                    right=mid-1;
                    
                }
            }
        }
        return -1;
    }
};
