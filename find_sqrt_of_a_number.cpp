class Solution {
public:
    int mySqrt(int n) 
    {
        long long int l = 0;
        long long int r = n;
        long long int ans = -1;
        while(l<=r)
        {
            long long int mid = l + (r-l)/2;
            long long int product = mid*mid;
            if(product<=n)
            {
                ans = mid;
                l=mid+1;
            }
            else
            r=mid-1;
        }
        return ans;
    }
};
