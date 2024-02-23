/* At any given point of time , in rotates sorted array with distinct elements , either  
1) [l,r] is sorted or
=> minimum = a[l] and we return
2) [l,mid] is sorted or
=> minimum = a[l] and we move to the right
3) [mid,r] is sorted
=> minimum = a[mid] and we move to the left
*/
class Solution {
public:
    int findMin(vector<int>& a) 
    {
        int n = a.size();
        int l=0;
        int r=n-1;
        int minimum=a[0];
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[l]<=a[mid] and a[mid]<=a[r])
            {
                // [l,r] is sorted
                minimum = min(minimum,a[l]); // minimum at a[l]
                return minimum;
            }
            else if(a[l]<=a[mid] and a[mid]>a[r])
            {
                //[l,mid] is sorted
                minimum = min(minimum,a[l]); // minimum at a[l]
                l=mid+1;
            }
            else
            {
                // [mid,r] is sorted
                minimum = min(minimum,a[mid]); // minimum at a[mid]
                r=mid-1;
            }
        }
        return minimum;
    }
};
