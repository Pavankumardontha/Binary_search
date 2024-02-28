bool isValid(int r, int c, int n, int m)
{
    if(r>=0 and r<n and c>=0 and c<m)
    return true;
    else
    return false;
}

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        int l=0;
        int r=n-1;
        int ans_row;
        int ans_col;
        while(l<=r)
        {
            int mid_row =  l + (r-l)/2; // middle row
            int mid_row_max = INT_MIN; // middle row maximum element
            int mid_row_max_col_ind; // col index of the maximum element in the mid row
            // traversing through the middle row
            for(int i=0;i<m;i++)
            {
                if(mid_row_max<mat[mid_row][i])
                {
                    mid_row_max=mat[mid_row][i];
                    mid_row_max_col_ind=i;
                }
            }
            bool ans = true; // assuming current element is the peak element
            if(isValid(mid_row+1,mid_row_max_col_ind,n,m))
            {
                if(mat[mid_row][mid_row_max_col_ind]<mat[mid_row+1][mid_row_max_col_ind])
                {
                    l=mid_row+1;
                    ans=false;
                }
            }
            if(isValid(mid_row-1,mid_row_max_col_ind,n,m))
            {
                if(mat[mid_row][mid_row_max_col_ind]<mat[mid_row-1][mid_row_max_col_ind])
                {
                    r=mid_row-1;
                    ans=false;
                }
            }
            if(ans==true)
            {
                ans_row=mid_row;
                ans_col=mid_row_max_col_ind;
                break;
            }
        }
        vector<int> result;
        result.push_back(ans_row);
        result.push_back(ans_col);
        return result;
    }
};
