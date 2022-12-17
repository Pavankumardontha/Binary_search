class Solution {
public:
    int firstBadVersion(int n) 
    {
        long left = 0;
        int right = n;
        while(left<right)
        {
            long mid = left + (right-left)/2;
            if(isBadVersion(mid))
            right = mid;
            else
            left = mid+1;
        }
        return left;
    }
};
