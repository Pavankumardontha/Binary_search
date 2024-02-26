/*
the no. of elements missed till the ith index = a[i]-i-1
ex:              [2,3,4,7,11] and k=5
index:           [0,1,2,3,4]
missed elements: [1,1,1,3,6]
Till index 0 the no. of elements missed : 1 =[1]
Till index 1 the no. of elements missed : 1 =[1]
Till index 2 the no. of elements missed : 1 =[1]
Till index 3 the no. of elements missed : 3 =[1,5,6]
Till index 4 the no. of elements missed : 6 =[1,5,6,8,9,10]

array :                 [2,3,4,7,11] l=0 , r=4 => mid=2 , k=5 ( we are looking for 5th missing element)
missed elements count : [1,1,1,3,6] 

first step : l=0,r=4 and mid=2 at index 2 we have only 1(<k) element missed so we move l to mid+1
second step: l=3 , r=4 and mid=3 at index 3 we have 3(<k) elements missed so we move l to mid+1
third step: l=4,r=4 and mid=4 at index 4 we have 6(>k) elements missed so we move r to mid-1
so finally r=3 and l=4 and the loop exists 

if we look at the range [r,l] we will have [7,11] and for sure our kth missed element falls between
these 2 numbers. So now we have the 2 elements between which our kth missed element belongs to. 
and from this we can easily find the kth missing element

*/

class Solution {
public:
    int findKthPositive(vector<int>& a, int k) 
    {
        int n = a.size();
        //checking the missed elements at index 1
        if(k<=a[0]-1)
        {
            return k;
        }
        if(k>a[n-1]-n)
        {
            return k+n;
        }
        int l =0;
        int r=n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(a[mid]-mid-1<k)
            l=mid+1;
            else
            r=mid-1;
        }
        return k+r+1;
    }
};
