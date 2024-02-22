/*
In a rotated sorted array with distinct elements always 
nums[0] > nums[n-1]
if its not , then it means its sorted
Here in rotated sorted array we will have 2 steeps both increasing. The minimum of the first steep (first element in the rotated sorted array) is always greater than the maximum of the second
steep(last element of the rotated sorted array)
The elements present in the first steep are always greater than the elements in the second 
steep since its rotated.
There are 6 cases here 
1) if a[mid] == target then return mid
2) if the target falls in first steep(a[l]<=target) and mid also falls in first steep(a[l]<=a[mid])
then we will have 2 conditions
a) if a[mid]>target => r=mid-1
b) if a[mid]<target => l=mid+1
3) if the target falls in first steep(a[l]<=target) and mid falls in the second steep(a[mid]<=a[r])
then r=mid-1
4) if the target falls in second steep(target<=a[r]) and mid falls in first steep(a[l]<=a[mid])
then l=mid+1
5) if the target falls second steep(target<=a[r]) and mid is also in second steep(a[mid]<=a[r])
then we will have 2 conditions
a) if a[mid]<target => l=mid+1
b) if a[mid]>target => r=mid-1
*/
class Solution {
public:
    int search(vector<int>& a, int target) 
    {
        int n = a.size();
        int l = 0;
        int r = n-1;
        int index=-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[mid]==target)
            return mid;
            else if(a[l]<=target and a[l]<=a[mid])
            {
                if(a[mid]>target)
                r=mid-1;
                else
                l=mid+1;
            }
            else if(a[l]<=target and a[mid]<=a[r])
            r=mid-1;
            else if(a[l]<=a[mid] and target<=a[r])
            l=mid+1;
            else
            {
                // both target and mid are in second steep
                // condition : (a[mid]<=a[r] and target<=a[r])
                if(a[mid]>target)
                r=mid-1;
                else
                l=mid+1;
            }
        }
        return index;
    }
};
