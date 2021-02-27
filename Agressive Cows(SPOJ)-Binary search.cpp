/* agressive cows SPOJ */

/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN 
(0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from 
hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. 
What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.

INPUT:
1
5 3
1
2
8
4
9

OUTPUT:
3

lets analyse the above case,we have 3 cows to be assigned positions. The locations of the barns in increasing order is 1,2,4,8,9(note that 
this order is sorted)

possibilities 
1) if we keep 3 cows in locations (1,2,4) then minimum distance between any 2 cows is 1
2) for locations (1,4,8) mininum distance is 3
3) for locations (1,8,9) minimum distance is 1
4) for locations (2,4,8) minimum distance is 2
5) for locations (4,8,9) minimum distance is 1

from the 5 possiblities the maximum possible ddistance that we could achieve between any 2 cows is 3 and is possible in case 2.
just from the values we can say that the maximum distance between 2 cows can be atmost a[n-1]-a[0] if a is sorted. a[] gives the locations of
barns.

let F(x) be some function which is either true or false.
F(x) is true when we can place all the given cows into different barns such that the minimum distance between any 2 cows is greater than or equal to x
so F(1) is true if we can place all the cows in the barns such that the minimum distance between any 2 cows is always greater than or equal to 1.
in the previous case,the maximum possible distance between 2 cows is a[n-1]-a[0]=9-1=8. so we start from 0 and go on upto to 8 and find the 
value of F(x) at each value(from 0 to maximum possible distance between  cows)

F(0)=TRUE
F(1)=TRUE
F(2)=TRUE
F(3)=TRUE
F(4)=FALSE
F(5)=FALSE
F(6)=FALSE
F(7)=FALSE
F(8)=FALSE

now from this function,we have to find the last index of the array that satisfies our property.Property(x) is that whether we can place all the 
cows in barns such that the minimum distance between  cows is greater than x.
*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int a[10000001];
int n;//no of barns
int k;//no of cows
int max_d;
bool property(int d)
{
	/*this function will return true if all the k cows can be placed in the barn such that the distance between 2 consecutive cows is 
	greater than or equal to d */
	int cnt=0;
	int pre;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			cnt++;
			pre=a[0];
		}
		else
		{
			if(a[i]-pre>=d)
			{
				cnt++;
				pre=a[i];
			}
		}
	}
	if(cnt>=k)
	return true;
	else
	return false;
}


int main()
{
	int t;
	cin>>t;
	int left;
	int right;
	int mid;
	while(t--)
	{
		cin>>n>>k;
		
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		sort(a,a+n);
		max_d=a[n-1]-a[0];
		
		left=0;
		right=max_d+1;
		
		while(left<right)
		{
			mid=(left)+(right-left)/2;
			/*we have to find the index of the last element which is true.This gives us the maximum possible distance out of the minimum 
			distances possible between 2 cows */
			if(!property(mid))
			right=mid;
			else
			left=mid+1;
			
		}
		cout<<left-1<<endl;
	}
}
