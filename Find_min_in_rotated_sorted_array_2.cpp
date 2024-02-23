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
