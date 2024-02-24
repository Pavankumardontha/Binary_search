class Solution {
public:
    int singleNonDuplicate(vector<int>& a) 
    {
        int n = a.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(mid==0 or mid==n-1)
            return a[mid];
            else
            {
                // no of elements in the array is always odd
                if(a[mid]!=a[mid-1] and a[mid]!=a[mid+1])
                return a[mid];
                else if(a[mid-1]==a[mid])
                {
                    if((mid-l+1)%2==0) // even no. of integers from [l,mid]
                    l=mid+1;
                    else
                    r=mid-2;
                }
                else
                {
                    //a[mid]==a[mid+1]
                    if((r-mid+1)%2==0)
                    r=mid-1;
                    else
                    l=mid+2;
                }
            }
        }
        return -1;
    }
};
