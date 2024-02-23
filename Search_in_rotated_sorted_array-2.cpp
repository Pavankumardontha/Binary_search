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
