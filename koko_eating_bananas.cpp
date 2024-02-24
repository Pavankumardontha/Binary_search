class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) 
    {
        /*
        if k = [0,1,2,3..............n] then
        for each value of k, we can either the complete the bananas in less than or equal to h
        Since we have asked for the minimum value we need to find the first True element
        In any hour , the maximum possible value of k is the maximum of the piles array. 
        If we keep k more than that also , its of no use because in the question its mentioned
        that "If the pile has less than k bananas, she eats all of them instead and will not eat 
        any more bananas during this hour."
        */
        int max_k_value = 0;
        int n = a.size();
        long long int sum = 0;
        for(int i=0;i<n;i++)
        {
            max_k_value = max(max_k_value,a[i]);
            sum = sum + a[i];
        }
        int l = 1;
        int r = max_k_value;
        int minimum_k_value;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int hours = 0;
            // calculate the no. of hours it takes if the koko eats mid bananas daily.
            for(int i=0;i<n;i++)
            {
                hours = hours + ceil((double)a[i]/(double)mid);
                if(hours>h)
                break;
            }
            if(hours <= h)
            {
                minimum_k_value = mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return minimum_k_value;
        // time complexity : O(N*log(Max(piles[])))
    }
};
