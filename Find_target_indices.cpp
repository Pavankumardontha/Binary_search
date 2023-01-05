
int find_first_index(vector<int> & a, int target)
{
    int n = a.size();
    int left = 0;
    int right = n-1;
    int first_index = -1; 
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(a[mid]<target)
        left = mid + 1;
        else 
        {
            /*we store the mid and reduce the search space by moving right index since we want the 
            first occurence index. We do the reverse ie move the left index if we want the last index
            occurence.*/
            if(a[mid]==target)
            first_index = mid;
            right = mid-1;
        }
    }
    return first_index;
}

int find_last_index(vector<int> &a, int target)
{
    int n = a.size();
    int left = 0;
    int right = n-1;
    int last_index = -1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(a[mid]>target)
        right = mid-1;
        else
        {
            if(a[mid]==target)
            last_index = mid;
            left = mid+1;
        }
    }
    return last_index;
}

class Solution {
public:
    vector<int> targetIndices(vector<int>& a, int target) 
    {
        sort(a.begin(),a.end());
        vector<int> ans;
        int first_index = find_first_index(a,target);
        int last_index = find_last_index(a,target);
        if(first_index ==-1)
        return ans;
        for(int i=first_index;i<=last_index;i++)
        ans.push_back(i);
        return ans;
    }
};
