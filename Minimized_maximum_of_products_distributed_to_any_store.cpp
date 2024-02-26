class Solution {
public:
    int minimizedMaximum(int shops, vector<int>& a) 
    {
        int n = a.size();
        int l = 1;
        int r = a[0];
        for(int i=0;i<n;i++)
        r=max(r,a[i]);
        int ans=-1;
        while(l<=r)
        {
            int mid =  l + (r-l)/2;
            int current_shops = 0;
            for(int i=0;i<n;i++)
            {
                current_shops=current_shops + a[i]/mid;
                if(a[i]%mid != 0)
                current_shops++;
            }
            if(current_shops>shops)
            l=mid+1;
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};
