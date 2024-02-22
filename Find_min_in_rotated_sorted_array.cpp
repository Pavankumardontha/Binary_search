f/*
Minimum element is always the starting element of the second steep.
Maximum element is always the ending element of the first steep.
mid can either be in the first steep or second steep. But minimum element will always lie in 
the second steep. So we try to move to the right if mid is in the first steep and move to the 
left if the mid is the second steep.
condition-1 if mid in first steep , l=mid+1
condition-2 if mid is in second steep then only there is a possibility that mid can be the minimum element so => minimum = min(minimum,a[mid]), r=mid-1

NOTE : This is used to search for an element in the rotated sorted array.
*/
class Solution {
public:
    int findMin(vector<int>& a) 
    {
        int n = a.size();
        int l = 0;
        int r = n-1;
        int minimum=a[0];
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[mid]>=a[0])
            {
                // if mid belongs to first steep
                l=mid+1;
            }
            else
            {
                // if mid belongs to the second steep a[mid]=<a[n-1] then only mid can be a possible minimum
                minimum=min(minimum,a[mid]);
                r=mid-1;
            }
        }
        return minimum;
    }
};
