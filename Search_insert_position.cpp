class Solution {
public:
    int searchInsert(vector<int>& a, int target) 
    {
        int left = 0;
        int right = a.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(target<a[mid])
            right = mid-1;
            else if(target==a[mid])
            return mid;
            else
            left = mid+1;
        }
        return left;   
    }
};
