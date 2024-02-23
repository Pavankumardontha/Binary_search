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


// METHOD - 2 : IMPORTANT AND USED IN FURTHER PROBLEMS.
/*
At any given point in time [l,r] is either
1) sorted
- if sorted we can check if target lies inside [l,r] and move according. if not we can return -1
2) unsorted
- check if [l,mid] sorted or [mid,r] is sorted. See if the target belongs to the sorted part. 
If it belongs to the sorted part , move towards the sorted part. If not move towards the unsorted
part.
We check if the target belongs to the sorted part. If it belongs , we move to the sorted part. If not we move to the unsorted part.
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
            {
                return mid;
            }
            else if(a[l]<=a[mid] and a[mid]<=a[r]) // [l,r] is sorted
            {
                if(a[l]<=target and target<=a[r]) // check if target belongs to the sorted part [l,r]
                {
                    if(target<a[mid])
                    r=mid-1;
                    else
                    l=mid+1;
                }
                else // target does not lie in [l,r]
                return -1; 
            }
            else if(a[l]<=a[mid] and a[mid]>a[r]) // left half [l,mid] is sorted
            {
                if(a[l]<=target and target<a[mid]) // check if target belongs to the sorted part [l,mid]
                r=mid-1;
                else
                l=mid+1;
            }
            else // right half [mid,r] is sorted
            {
                if(a[mid]<target and target<=a[r]) // check if target belongs to the sorted part [mid,r]
                l=mid+1;
                else
                r=mid-1;
            }
        }
        return -1;
    }
};









