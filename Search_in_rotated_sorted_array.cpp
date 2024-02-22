/*
In a rotated sorted array we have conditions 
1) if both target and mid belong to the first steep
a) if a[mid]> target => r = mid-1;
b) if a[mid]<target => l=mid+1
2) if target in first steep and mid in second steep => r = mid-1
3) if target in second steep and mid in first steep => l = mid+1
4) if target in second steep and mid in second steep 
a) if a[mid] > target => r = mid-1;
b) if a[mid] < target => l = mid+1;
*/
class Solution {
public:
    int search(vector<int>& a, int target) 
    {
        int n = a.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[mid]==target)
            return mid;
            else if(a[0]<=target and a[0]<=a[mid])
            {
                if(a[mid]>target)
                r=mid-1;
                else
                l=mid+1;
            }
            else if(a[0]<=target and a[mid]<=a[n-1])
            r=mid-1;
            else if(target<=a[n-1] and a[mid]>=a[0])
            l=mid+1;
            else
            {
                if(a[mid]>target)
                r=mid-1;
                else
                l=mid+1;
            }
        }
        return -1;
    }
};
