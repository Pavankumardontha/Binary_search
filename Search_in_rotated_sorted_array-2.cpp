/*
Here there might be a problem where a[l] = a[r] = a[mid] in this case , we will not be able 
to know in which direction to move either to the left or to the right. In this case , we will
move to the left and as well to the right by 1, ie 
l++ and r--;

consider the first case : [1,0,1,1,1],target=0 
here l=0 and r=4 , mid=2 and a[mid]=a[l]=a[r]=1 here we will not know in which direction we need
to move. We cannot exactly tell in which steep the target and mid lies.

consider the second case : [1,2,0,1,1] , target=2
l=0,r=4=> mid=2 a[l]=a[r]=1 a[mid]=0
Here we can clearly decide on which direction to move. So only when a[l]=a[mid]=a[r] we cannot 
decide the direction to move.
*/

class Solution {
public:
    bool search(vector<int>& a, int target) 
    {
        int n = a.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[mid]==target)
            return true;
            if(a[l]==a[mid] and a[l]==a[r])
            {
                // extra case that needs to be handled than the previous problem
                l++;
                r--;
            }
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
                // if a[mid]<=a[r] and target<=a[r]
                if(a[mid]>target)
                r=mid-1;
                else
                l=mid+1;
            }
        }
        return false;
    }
};
