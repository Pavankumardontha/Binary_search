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



/* Same code written more neatly */
class Solution {
public:
    bool isValid(int i, int j, int n, int m)
    {
        if(i>=0 and i<n and j>=0 and j<m)
        return true;
        return false;
    }
    int get(vector<vector<int>> &mat, int i, int j, int n, int m)
    {
        if(isValid(i,j,n,m))
        return mat[i][j];
        else
        return -1;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        /*
        Same like peak element - 1 , instead of left and right, here we will have top,down,right,left 
        We move in the direction of max of (top,down,left,right) if current index is not maximum. 
        If current_index is maximum we return it. 
        
        */
        // we will apply binary search on the rows
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = n-1;
        vector<int> ans;
        while(l<=r)
        {
            int mid_row =  l + (r-l)/2; // middle row
            int mid_row_max = INT_MIN; // maximum element of the middle row
            int mid_row_max_col_ind; // col index of the maximum element in the mid row

            // iterate through all the elements in this row to find the maximum
            for(int i=0;i<m;i++)
            {
                if(mid_row_max < mat[mid_row][i])
                {
                    mid_row_max = mat[mid_row][i];
                    mid_row_max_col_ind = i;
                }
            }

            /* 
            we want to decide whethere we need to move up(r = mid_row-1) or whether we need to move down(l=mid+1). We can decide this by finding the maximum element 
            among (mid_row-1, mid_row, mid_row+1)
            */
            if(mat[mid_row][mid_row_max_col_ind] < get(mat,mid_row-1,mid_row_max_col_ind,n,m) or mat[mid_row][mid_row_max_col_ind] < get(mat,mid_row+1,mid_row_max_col_ind,n,m))
            {
                // if mid element is the greatest less than either one of the (mid_row-1) and (mid_row+1)
               if(get(mat,mid_row-1,mid_row_max_col_ind,n,m) > get(mat,mid_row+1,mid_row_max_col_ind,n,m))
               {
                    // move up
                    r = mid_row-1;
               }
               else
               {
                    // move down
                    l = mid_row+1;
               }
            }
            else
            {
                // obvious answer is mat[mid_row][mid_row_max_col_id]
                ans.push_back(mid_row);
                ans.push_back(mid_row_max_col_ind);
                break;
            }
        }
        return ans;
    }
};













