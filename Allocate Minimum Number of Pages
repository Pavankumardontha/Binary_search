/*You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each 
permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, 
the task is to find that particular permutation in which the maximum number of pages allocated to a student is 
minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the 
explanation for better understanding).
*/

#include<iostream>
using namespace std;
#include<bits/stdc++.h>
long long int sum;
long long int a[1000001];
long long int k;//no of students
int n;
bool property(long long int rsum)
{
    int cnt=0;//this will count the minimum no of students required so that no 
    //student will get more than n(rsum) pages to read
    long long int csum=0;//current sum
    for(int i=0;i<n;i++)
    {
        if(csum+a[i]>rsum)
        {
            cnt++;
            csum=a[i];
        }
        else
        csum=csum+a[i];
    }
    if(cnt+1>k)
    return false;
    else
    return true;
}
int main()
{
    int t;
    cin>>t;
    long long int mx;
    long long int left;
    long long int right;
    long long int mid;
    while(t--)
    {
        cin>>n;
        sum=0;
        mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum=sum+a[i];
            mx=max(a[i],mx);
        }
        cin>>k;
        //sort(a,a+n);
        if(k==1)
        cout<<sum<<endl;
        else if(k==0)
        cout<<-1<<endl;
        else if(k>n)
        cout<<-1<<endl;
        else
        {
        left=mx;//maximum element in the array
        right=sum;//sum of all elements in the array
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(property(mid))
            right=mid;
            else
            left=mid+1;
            //cout<<left<<" "<<right<<endl;
        }
        if(left==sum)
        cout<<-1<<endl;
        else
        cout<<left<<endl;
        }
    }	
	return 0;
}
