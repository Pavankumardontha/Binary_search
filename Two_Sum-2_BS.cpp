class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) 
    {
        int n = a.size();
        int left = 0;
        int right = n-1;
        vector<int> ans;
        while(left<right)
        {
            int k = a[left] + a[right];
            if(k==target)
            break;
            else if(k<target)
            left++;
            else
            right--;
        }
        ans.push_back(left+1);
        ans.push_back(right+1);
        return ans;
    }
};
