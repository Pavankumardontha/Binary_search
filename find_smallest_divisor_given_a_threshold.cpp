class Solution {
public:
    int smallestDivisor(vector<int>& a, int threshold) 
    {
        int n = a.size();
        int l = 1;
        int r =0;
        for(int i=0;i<n;i++)
        r = max(r,a[i]);
        int ans = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int sum = 0;
            for(int i=0;i<n;i++)
            {
                sum = sum + ceil((double)a[i]/mid);
                if(sum>threshold)
                break; 
            }
            if(sum<=threshold)
            {
                ans = mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};
