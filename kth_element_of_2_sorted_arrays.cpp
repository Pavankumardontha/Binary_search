class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int no_of_elements_to_be_picked = k;
        int no_of_elements_picked_from_arr1=0;
        int no_of_elements_picked_from_arr2=0;
        if(m>n)
        {
            //we apply BS only on the smaller of the 2 arrays
            return kthElement(arr2,arr1,m,n,k);
        }
        int l1,l2,r1,r2;
        int l=0;
        int r=min(n,k); // max no. of elements that we can pick from arr1. We have to pick the minium of (n,k)
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            no_of_elements_picked_from_arr1 = mid; // always less than n
            no_of_elements_picked_from_arr2 = k - mid;
            if(no_of_elements_picked_from_arr2 > m)
            {
                //pick more elements from arr1
                l=mid+1;
            }
            else
            {
                l1 = INT_MIN;
                l2 = INT_MIN;
                r1 = INT_MAX;
                r2 = INT_MAX;
                
                // l1 , r1 calculation
                if(no_of_elements_picked_from_arr1 == 0)
                {
                    // no l1 
                    r1 = arr1[no_of_elements_picked_from_arr1];
                }
                else if(no_of_elements_picked_from_arr1 == n)
                {
                    // no r1
                    l1 = arr1[n - 1];
                }
                else
                {
                    // both exist
                    l1 = arr1[no_of_elements_picked_from_arr1-1];
                    r1 = arr1[no_of_elements_picked_from_arr1];
                }
                
                // l2,r2 calculation
                
                if(no_of_elements_picked_from_arr2 == 0)
                {
                    // no l2 
                    r2 = arr2[no_of_elements_picked_from_arr2];
                }
                else if(no_of_elements_picked_from_arr2 == m)
                {
                    //no r2
                    l2 = arr2[m-1];
                }
                else
                {
                    // both exist
                    l2 = arr2[no_of_elements_picked_from_arr2-1];
                    r2 = arr2[no_of_elements_picked_from_arr2];
                }
                
                // check validity 
                if(l1<=r2 and l2<=r1)
                {
                    // valid 
                    return max(l1,l2);
                }
                else if(l1>r2)
                {
                    // we need to push l to the right side to we move the right pointer to mid-1
                    r = mid-1;
                }
                else
                {
                    // similar to above
                    l = mid + 1;
                }
            }
        }
    }
};
