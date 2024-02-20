/*
Let the given target be x
let l = index of the last element which is strictly less than x
then the insertion position = l + 1
*/
int get_last_element_index_less_than_target(vector<int> &a,int target)
{
    int n = a.size();
    int l=0;
    int r=n-1;
    int index=-1;
    while(l<=r)
    {
        int m = l + (r-l)/2;
        if(a[m]==target)
        r=m-1;
        else if(a[m]>target)
        r=m-1;
        else
        {
            index = m;
            l=m+1;
        }
    }
    return index;
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        return get_last_element_index_less_than_target(nums,target) + 1;
        
    }
};
