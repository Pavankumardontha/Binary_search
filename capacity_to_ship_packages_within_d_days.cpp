class Solution {
public:
    int shipWithinDays(vector<int>& a, int days) 
    {
        int n = a.size();
        long long int l = a[0];
        long long int r = 0;
        long long int ans;
        for(int i=0;i<n;i++)
        {
            r = r + a[i];
            if(l<a[i])
            l=a[i];
        }
        while(l<=r)
        {
            long long int mid = l + (r-l)/2;
            // mid is our current max capacity
            int current_days=0;
            int current_capacity=0;
            for(int i=0;i<n;i++)
            {
                current_capacity = current_capacity+a[i];
                if(current_capacity>mid)
                {
                    //current_capacity>=mid
                    current_capacity=a[i];
                    current_days++;
                    if(current_days>days)
                    break;
                }
            }
            current_days++;
            if(current_days<=days)
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
