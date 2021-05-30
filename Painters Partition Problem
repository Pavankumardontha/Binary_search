
/*
Problem Description :- 
Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k 
painters for this work and each painter takes 1 unit time to paint 1 unit of the board. The problem is to find the minimum time to get this job done if all painters start 
together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.
NOTE:- This is very much similar to allocate minimum no. of pages problem. !!!
*/






bool property(int a[],int n,int k, long long int d)
{
    int cnt = 0;
    long long int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>d)
        return false;
        
        if(sum+a[i]<=d)
        sum = sum + a[i];
        else
        {
            cnt++;
            sum = a[i];
        }
    }
    if(cnt+1<=k)
    return true;
    else
    return false;
}
class Solution
{
    public:
    long long minTime(int a[], int n, int k)
    {
        long long int left=INT_MIN; // max element in the array 
        long long int right=0;// sum of all array elements
        for(int i=0;i<n;i++)
        {
            if(left<a[i])
            left = a[i];
            right = right + a[i];
        }
        
        while(left<right)
        {
            long long int mid = left + (right-left)/2;
            if(property(a,n,k,mid))
            right = mid;
            else
            left = mid + 1;
        }
        return left;
    }
};
