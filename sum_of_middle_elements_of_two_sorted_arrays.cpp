class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) 
    {
        /* NOTE: Similar to median of 2 sorted arrays
        pick elements (n+1)/2, where n=n1+n2 
        */
        int n1=arr1.size();
        int n2=arr2.size();
        int n = n1+n2;
        int total_no_of_elements_to_be_picked=(n+1)/2;
        int l=0;
        int r=min(total_no_of_elements_to_be_picked,n1);
        int mid; // no_of_elements_to_be_picked_from_arr1
        int l1,l2,r1,r2;
        int no_of_elements_to_be_picked_from_arr2;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            no_of_elements_to_be_picked_from_arr2 = total_no_of_elements_to_be_picked-mid;
            if(no_of_elements_to_be_picked_from_arr2>n2)
            {
                // pick more elements from arr1
                l=mid+1;
            }
            else
            {
                // find l1,l2,r1,r2 and check whether its the correct combination or not
                if(mid==0)
                l1 = INT_MIN;
                else
                l1 = arr1[mid-1];
                
                if(mid==n1)
                r1=INT_MAX;
                else
                r1=arr1[mid];
                
                if(no_of_elements_to_be_picked_from_arr2==0)
                l2=INT_MIN;
                else
                l2=arr2[no_of_elements_to_be_picked_from_arr2-1];
                
                if(no_of_elements_to_be_picked_from_arr2==n2)
                r2=INT_MAX;
                else
                r2=arr2[no_of_elements_to_be_picked_from_arr2];
                
                //check for the combination
                if(l1<=r2 and l2<=r1)
                {
                    return (max(l1,l2) + min(r1,r2));
                }
                else if(l1>r2)
                {
                    // pick less from arr1
                    r=mid-1;
                }
                else
                l=mid+1;
            }
            
        }
        return -1;
    }
};
