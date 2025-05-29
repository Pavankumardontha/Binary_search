class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        /*
        Read the conditions properly before going into the solution. There are 2 main conditions for this problem
        a) Integers in each row are sorted in ascending from left to right.
        b) Integers in each column are sorted in ascending from top to bottom.

        Here are the solutions for the problem.
        1) brute force approach O(M*N)
        2) Apply binary search on each row or each column. Time complexity: O(MlogN) or O(NlogM)
        3) Start from the top right corner. Compare it with the target and then eliminate the row or col accordingly
        O(M+N)
        */
        int rows = mat.size();
        int cols = mat[0].size();
        int r=0;
        int c=cols-1;
        while(r<rows and c>=0)
        {
            if(mat[r][c]==target)
            return true;
            else if(target<mat[r][c])
            c--;
            else
            r++;
        }
        return false;
    }
};
