int no_of_elements_greater_than_or_equal(vector<vector<int>> &mat, int x)
{
    /*
    Function used to find the no. of elements in the matrix greater than or equal to x.
    for a row , let the first occurance of element greater than or equal to x be at index i. then the 
    no. of elements in the matrix greater than or equal to x = n-i where n is the column size
    */
    int r = mat.size();
    int c = mat[0].size();
    int n = r*c;
    int cnt = 0;
    for(int i=0;i<r;i++)
    {
        int l=0;
        int r=c-1;
        int ans = n;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(mat[i][mid]<x)
            l=mid+1;
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        cnt = cnt + (n-ans);
    }
    return cnt;
}

int no_of_elements_less_than_or_equal(vector<vector<int>> &mat, int x)
{
    /*
    Funtion used to find the no. of elements in the matrix less than or equal to x.
    */
    int r = mat.size();
    int c = mat[0].size();
    int cnt = 0;
    for(int i=0;i<r;i++)
    {
        int l=0;
        int r=c-1;
        int ans = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(mat[i][mid]<=x)
            {
                ans=mid;
                l=mid+1;
            }
            else
            r=mid-1;
        }
        cnt = cnt + (ans+1); // if ans==-1 cnt will not increment
    }
    return cnt;
}

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C)
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
        */ 
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows*cols; // no. of elements in the matrix
        for(int i=0;i<rows;i++)
        {
            minimum = min(minimum,matrix[i][0]);
            maximum = max(maximum,matrix[i][cols-1]);
        }
        
        int l = minimum;
        int r = maximum;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int no_of_elements_less_than_or_equal_to_mid = no_of_elements_less_than_or_equal(matrix, mid);
            int no_of_elements_greater_than_or_equal_to_mid = no_of_elements_greater_than_or_equal(matrix, mid);
            if(no_of_elements_less_than_or_equal_to_mid == no_of_elements_greater_than_or_equal_to_mid)
            return mid;
            else if(no_of_elements_less_than_or_equal_to_mid < (n+1)/2)
            l=mid+1;
            else
            r=mid-1;
        }
    }
};
