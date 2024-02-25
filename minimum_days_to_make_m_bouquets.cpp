class Solution {
public:
    int minDays(vector<int>& a, int m, int k) 
    {
        int n = a.size();
        long long int k1 = m*1LL*k;
        if(k1>n)
        return -1;

        // max value of days = max value of bloomDay array
        int max_value = 0;
        for(int i=0;i<n;i++)
        max_value = max(max_value,a[i]);

        long long int l=1;
        long long int r=max_value;
        long long int ans = -1;
        while(l<=r)
        {
            long long int mid = l + (r-l)/2;
            int bouquets=0;
            int consecutive_count=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]<=mid)
                {
                    consecutive_count++;
                    if(consecutive_count==k)
                    {
                        bouquets++;
                        consecutive_count=0;
                    }
                }
                else
                consecutive_count=0;
                if(bouquets==m)
                break;
            }
            if(bouquets==m)
            {
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};
