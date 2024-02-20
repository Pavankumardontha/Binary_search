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

//---- APPROACH-2 -------
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int required_number = target-nums[i];
            cout<<required_number<<endl;
            if(mp.find(required_number) != mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[required_number]);
                break;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};
