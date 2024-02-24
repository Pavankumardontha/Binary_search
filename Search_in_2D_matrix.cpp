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
