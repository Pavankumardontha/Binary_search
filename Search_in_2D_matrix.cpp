class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        /*
        We can do it in 4 ways
        1) Traverse through the entire array to find the target time complexity = O(N*M)
        2) Traverse through all the rows and find if the target falls between the first element and the last element
        of that row. If it falls then do a binary search in that row. Time complexity = O(N) + O(logM)
        3) Apply BS on the first column and find an element which is just less than or equal to target. Apply binary
        search on that row. Time complexity = O(logN + logM)
        4) Think of it as 1D array and apply BS on the entire array. 
        lets say we have the given matrix below
        [1,2,3]
        [4,5,6]
        n=no_of_rows=2, m=no_of_cols=3
        We have total 6 elements so the last index if treated as a 1d array will be 8. 
        array elements: 1,2,3,4,5,6
        array indexes:  0,1,2,3,4,5
        so take l=0 , r=5 and apply BS in this range. 
        1) l=0,r=5 => mid = 2 -> we need to convert this mid index to matrix index pointing to some (i,j)
        In the 1D array index 2 points to value 3 which is present at index (0,2) in 2D array.
        we can convert a 1D index into a 2D index by i=(1D index)/m , j = (1D index)%m
        so for 1D index of 4 , we have i=2/3=0 and j=2%3=1 => (i,j) = (0,2)
        Time complexity = log(M*N)
        */

        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = n*m-1;
        int mid;
        int mid_row;
        int mid_col;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            mid_row = mid/m;
            mid_col = mid%m;
            if(mat[mid_row][mid_col]==target)
            return true;
            else if(mat[mid_row][mid_col]<target)
            l=mid+1;
            else
            r=mid-1;
        }
        return false;
    }
};



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        // understand the difference between the gfg and leetcode problem
        // start from the first row and last column (striver youtube approach)
        int r = 0;
        int c = matrix[0].size()-1;
        while(r<matrix.size() and c>=0)
        {
            if(matrix[r][c]==target)
            return true;
            else if(target<matrix[r][c])
            c--;
            else
            r++;
        }
        return false;
    }
};

// solution reference : https://leetcode.com/problems/search-a-2d-matrix/solutions/1895837/c-binary-search-tree-explained-with-img/
