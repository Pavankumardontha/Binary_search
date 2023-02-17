class Solution {
public:
    bool search(vector<int>& a, int target) 
    {
        int left = 0;
        int right = a.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(a[mid]==target)
            return true;
            else if(a[left]==a[mid] and a[mid]==a[right])
            {
                // only different step from rotated sorted array 1
                left++;
                right--;
            }
            else if(a[left]<=a[mid] and a[mid]<=a[right])
            {
                //[left,right] is sorted
                if(a[left]<=target and target<a[mid])
                right = mid-1;
                else
                left = mid+1;
            }
            else
            {
                //[left,right] is not sorted so either
                //[left,mid] is sorted or 
                // [mid,right] is sorted
                if(a[left]<=a[mid] and a[mid]>=a[right])
                {
                    //[left,mid] is sorted
                    if(a[left]<=target and target<a[mid])
                    right = mid-1;
                    else
                    left = mid+1;
                }
                else
                {
                    if(a[mid]<target and target<=a[right])
                    left = mid+1;
                    else
                    right = mid-1;
                }
            }
        }
        return false;
    }
};
