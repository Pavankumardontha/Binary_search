class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) 
    {
        int n = a.size();
        int left = 0;
        int right = n-1;
        int ans=0;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(mid!=0 and mid!=n-1)
            {
                /* this implies that both mid-1 and mid+1 will exist */
                if(a[mid-1]<a[mid] and a[mid]>a[mid+1])
                {
                    // mid is the answer
                    return mid;
                }
                else if(a[mid]<a[mid+1])
                {
                    // move right to get to the peak element 
                    left = mid+1;
                }
                else
                {
                    //move left to get to the peak element
                    if(a[ans]<a[mid])
                    ans = mid;
                    right = mid-1;
                }
            }
            else if(mid==0)
            {
                if(a[mid]>a[mid+1])
                return mid;
                else
                left = mid+1;
            }
            else
            {
                // mid = n-1 in this case
                if(a[mid]>a[mid-1])
                return mid;
                else
                right = mid-1;
            }
        }
        return ans;
    }
};
