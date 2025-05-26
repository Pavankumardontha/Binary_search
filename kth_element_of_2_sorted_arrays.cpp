class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) 
    {
        /*
        NOTE: Helps in solving the median of 2 sorted arrays. (do median of 2 sorted arrays before doing this)
        Lets say we want to find the first k elements from 2 sorted arrays a,b
        If we select x elements from a, we should select x-k elements from b
        How do we know whether the selection is correct or not ??
        based on the condition : 
        l1<r1 and l2<r1
        We need to pick the bounds of array a and array b which form the first
        k elements when sorted combinely.
        */
        int total_no_of_elements_to_be_picked = k; 
        int n1 = a.size();
        int n2 = b.size();
        int l=0;
        int r=min(total_no_of_elements_to_be_picked,n1);
        int mid; // no_of_elements that we are picked from array a
        int no_of_elements_to_be_picked_from_b;
        /* 
        here we are directly applying binary search on array a, but we can find the 
        shorted of both and apply bs on the shorted array
        */
        int l1,l2,r1,r2;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            no_of_elements_to_be_picked_from_b = total_no_of_elements_to_be_picked - mid;
            if(no_of_elements_to_be_picked_from_b > n2)
            {
                // we need to pick more elements from a
                l=mid+1;
            }
            else
            {
                // find l1,l2,r1,r2 and check if its the correct combination or not
                if(mid==0)
                l1=INT_MIN;
                else
                l1=a[mid-1];
                
                if(mid==n1)
                r1=INT_MAX;
                else
                r1=a[mid];
                
                if(no_of_elements_to_be_picked_from_b==0)
                l2=INT_MIN;
                else
                l2=b[no_of_elements_to_be_picked_from_b-1];
                
                if(no_of_elements_to_be_picked_from_b==n2)
                r2=INT_MAX;
                else
                r2=b[no_of_elements_to_be_picked_from_b];
                
                if(l1<=r2 and l2<=r1)
                {
                    // correct combination
                    return max(l1,l2);
                }
                else if(l1>r2)
                {
                    // pick less from a
                    r=mid-1;
                }
                else
                l=mid+1;
            }
        }
        return -1;
    }
};
