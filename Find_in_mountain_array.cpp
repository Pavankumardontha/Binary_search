/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

int FindPeakIndex(MountainArray &a)
{
    int n = a.length();
    int left = 0;
    int right = n-1;
    int ans = 0;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        int mid_element = a.get(mid);
        if(mid!=0 and mid!=n-1)
        {
            int mid_left_element = a.get(mid-1);
            int mid_right_element = a.get(mid+1);
            if(mid_left_element < mid_element and mid_element > mid_right_element)
            return mid;
            else if(mid_element < mid_right_element)
            {
                // move right
                left = mid+1;
            }
            else
            {
                // move left
                if(a.get(ans)<mid_element)
                ans = mid;
                right = mid-1;
            }
        }
        else if(mid==0)
        {
            int mid_right_element = a.get(mid+1);
            if(mid_element > mid_right_element)
            return mid;
            else
            {
                // move right 
                left = mid+1;
            }
        }
        else
        {
            // mid = n-1 here
            int mid_left_element = a.get(mid-1);
            if(mid_element > mid_left_element)
            return mid;
            else
            {
                // move left
                right = mid-1;
            }
        }
    }
    return ans;
}

class Solution {
public:
    int findInMountainArray(int target, MountainArray &a) 
    {
        int peak_ind = FindPeakIndex(a);
        /*
        We now got the peak element we need to see where the target falls in 
        it can fall either in 
        1) [0,peak_ind] or 
        2) [peak_ind,n-1]
        3) It can also fall in 2 ranges Ex: [1,5,2] and target = 2. Here 
        peak_ind = 1 , target falls in [0,peak_ind] and also in [peak_ind,right] so we need to apply binary search 
        first on range [0,peak_ind] and then on the range [peak_ind,right]
        */
        int n = a.length();
        int left,right,mid;
        if(a.get(0)<= target and target<= a.get(peak_ind))
        {
            // target belongs to [0,peak_ind]
            left = 0;
            right = peak_ind;
            while(left<=right)
            {
                mid = left + (right-left)/2;
                int mid_element = a.get(mid);
                if(mid_element == target)
                return mid;
                else if(mid_element<target)
                left = mid + 1;
                else
                right = mid - 1;
            }
        }
        if(a.get(peak_ind)>= target and target>= a.get(n-1))
        {
            cout<<peak_ind<<endl;
            left = peak_ind;
            right = n-1;
            while(left<=right)
            {
                mid = left + (right-left)/2;
                int mid_element = a.get(mid);
                if(mid_element == target)
                return mid;
                else if(mid_element<target)
                right = mid-1;
                else
                left = mid+1;
            }
        }
        return -1;
    }
};
