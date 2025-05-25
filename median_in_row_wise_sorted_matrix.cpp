// User function template for C++
int no_of_elements_less_than_or_equal(vector<vector<int>> mat,int k)
{
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        // find the no. of elements which are less than or equal to k in current row
        int l = 0;
        int r = m-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(mat[i][mid]<=k)
            {
                ans = ans + (mid-l+1);
                l = mid+1;
            }
            else
            r=mid-1;
        }
    }
    return ans;
}

int no_of_elements_greater_than_or_equal(vector<vector<int>> mat,int k)
{
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int l = 0;
        int r = m-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(mat[i][mid]>=k)
            {
                ans = ans + (r-mid+1);
                r=mid-1;
            }
            else
            l=mid+1;
        }
    }
    return ans;
}

class Solution {
  public:
    int median(vector<vector<int>> &mat) 
    {
        /*
        Since R,C are odd , the no. of elements = R*C = odd and so there is one element for the median calculation
        Lets take an example of an array of odd size a=[1,2,3,3,3,3,4,4,4]
        If a number x is median for an array of size n , then 
        1) There should be minimum of (n+1)/2 elements less than or equal to x to the left including the number
        2) There should be minimum of (n+1)/2 elements greater than or equal to x to the right including the number
        
        So in the above example , 
        the element at the index = 4 (element = 3) is the median because there are 
        6 ( greater than (n+1)/2 )elements to the right of 3 which are greater than or equal to 3 
        and 7 ( greater than (n+1)/2 ) elements to the left of 3 which are lesser than or equal to 3.
        
        
        We will find the minimum of the matrix(min of first column) and maximum value(max of the last column)
        and apply binary search in this range. We will find a number where the no. of elements less than or equal
        to x is atleast (n+1)/2 and the number of elements which are greater than or equal to x is also 
        atleast (n+1)/2. 

        Example: 
        consider the case
        [1,2,28]
        [29,30,30]
        [32,33,34]
        After sorting the above matrix we get: [1,2,28,29,30,30,32,33,34]
        here 30 is the median. 
        But, no. of elements which are less than or equal to 30 = 6
        and no. of elements which are greater than or equal to 30 = 5
        clearly both are equal. But the no of elements greater than or equal to 30 are 6 and the no. of elements less than or equal to 30 are 5.
        Both the values are greater than or equal to (n+1)/2. here n is the total no. of elements = 3*3 = 9

        TIME COMPLEXITY: O(n log m * log(maxVal – minVal))
        SPACE COMPLEXITY: O(1)
        */ 
        int n = mat.size();
        int m = mat[0].size();
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        // minimum belongs to the first col and maximum belongs to the last col
        for(int i=0;i<n;i++)
        {
            minimum = min(minimum,mat[i][0]);
            maximum = max(maximum,mat[i][m-1]);
        }
        int l = minimum;
        int r = maximum;
        int total_no_of_elements = n*m;
        int mid;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            int l1 = no_of_elements_less_than_or_equal(mat,mid);
            int l2 = no_of_elements_greater_than_or_equal(mat,mid);
            if(l1>=(total_no_of_elements+1)/2 and l2>=(total_no_of_elements+1)/2)
            return mid;
            else if(l1<(total_no_of_elements+1)/2)
            l=mid+1;
            else
            r=mid-1;
        }
    }
};

