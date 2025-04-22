class Solution {
public:
    int mySqrt(int x) 
    {
        /*
        From 1 to x/2, find the last element 'i' that satisfies the condition i*i<=x 
        The square root of x lies between [1,x/2]
        */
        if(x == 1 or x==0)
        return x;
        int l = 0;
        int r = x/2;
        int ans = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            long long int temp = mid*1LL*mid;
            if(temp <= x)
            {
                ans = mid;
                l = mid+1;
            }
            else
            r=mid-1;
        }
        return ans;
    }
};
