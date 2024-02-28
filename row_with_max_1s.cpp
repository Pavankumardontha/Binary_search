int rowWithMax1s(vector<vector<int>> &mat, int n, int m) 
{
    /*
    apply binary search on all the rows of the matrix. Time complexity : O(n*logm)
    n=no. of rows
    c=no. of cols
    */
    int max_ones = 0;
    int max_row=-1;
    for(int i=0;i<n;i++)
    {
        int l = 0;
        int r = m-1;
        int index=-1;
        int ones_count = 0;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(mat[i][mid]==1)
            {
                index=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        if(index==-1)
        ones_count=0;
        else
        ones_count=m-index;
        if(ones_count>max_ones)
        {
            max_ones=ones_count;
            max_row=i;
        }
    }
    return max_row;
}
