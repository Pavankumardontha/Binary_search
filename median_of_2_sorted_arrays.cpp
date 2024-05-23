 /*
        Approach 1: Merge and Sort
        Create a new array with a size equal to the total number of elements in both input arrays.
        Insert elements from both input arrays into the new array.
        Sort the new array.
        Find and return the median of the sorted array.
        Time Complexity: In the worst case TC is O((n + m) * log(n + m)).
        Space Complexity: O(n + m), where ‘n’ and ‘m’ are the sizes of the arrays.
*/
/*
        Approach 2: Two-Pointer Method
        Initialize two pointers, i and j, both initially set to 0.
        Move the pointer that corresponds to the smaller value forward at each step.
        Continue moving the pointers until you have processed half of the total number of        
        elements.
        Calculate and return the median based on the values pointed to by i and j.
        Time Complexity: O(n + m), where ‘n’ & ‘m’ are the sizes of the two arrays.
        Space Complexity: O(1).

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total_length = n1+n2;
        int i=0;
        int j=0;
        vector<double> mid_elements;
        while(i<n1 and j<n2)
        {
            int index = i+j; //current element index
            if(nums1[i]<=nums2[j])
            {
                if(index==(total_length)/2)
                mid_elements.push_back(double(nums1[i]));
                if(total_length%2==0 and index == (total_length)/2 - 1)
                mid_elements.push_back(double(nums1[i]));
                i++;
            }
            else
            {
                if(index==(total_length)/2)
                mid_elements.push_back(double(nums2[j]));
                if(total_length%2==0 and index == (total_length)/2 - 1)
                mid_elements.push_back(double(nums2[j]));
                j++;
            }
        }
        while(i<n1)
        {
            int index = i+j;
            if(index==(total_length)/2)
            mid_elements.push_back(double(nums1[i]));
            if(total_length%2==0 and index == (total_length)/2 - 1)
            mid_elements.push_back(double(nums1[i]));
            i++;
        }
        while(j<n2)
        {
            int index = i+j;
            if(index==(total_length)/2)
            mid_elements.push_back(double(nums2[j]));
            if(total_length%2==0 and index == (total_length)/2 - 1)
            mid_elements.push_back(double(nums2[j]));
            j++;
        }
        if(total_length%2)
        {
            return mid_elements[0];
        }
        else
        {
            return (mid_elements[0] + mid_elements[1])/2;
        }
    }
};

/* 
Approach - 2 : Using binary search on the smaller array
Time complexity = O(min(n,m))
Space complexity = O(1)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        /*
        To find the median , we always need the middle elements. 
        In other words , if we have 2 sorted arrays of size n1 and n2 , then we need to find 
        the elements (n1+n2)/2 and (n1+n2)/2-1 (in even cases) to find its median. 
        Lets imagine a case where 
        a = 8,12,19,23,31 b=2,9,17,29 
        combined sorted array: 2,8,9,12,17,19,23,29,31
        median = mid element = 4th index = 17
        Now n1=5,n2=4 => total elements = 9 
        so we need to (9)/2 = 4th index element = 5th element => we need to pick atleast 5 
        elements to find the median. 

        Notice the first half of the combined array 2,8,9,12,17 . This part is formed by taking
        elements a:[8,12] and b:[2,9,17] . 
        No. of elements we need to take to find median = (total+1)/2 = (9+1)/2 = 5
        Now these 5 elements can be picked in such a way that 
        a b
        0 5 -> picking 0 elements from a and all 5 elements from b -> Not possible since b has only 4 elements
        1 4 -> picking 1 element from a and rest 4 from b -> a:[8] b:[2,9,17,29]
        2 3 -> a:[8,12] b:[2,9,17] -> CORRECT COMBINATION
        3 2 -> a:[8,12,19] b:[2,9] -> WRONG COMBINATION (we will understand why this is wrong below)
        4 1 -> a:[8,12,19,23] b:[2] -> WRONG COMBINATION
        5 0 -> a:[8,12,19,23,31] b:[] -> WRONG COMBINATION
        
        Let the no. of elements needed to pick for median = x 
        If we pick n elements from array a , then we need to pick x-n elements for sure from array b. 
        So in other words , we need to apply binary search on array a to find the no. of elements that we can pick from a 
        by which we can directly tell the no. of elements which we can pick from b. 
        So we need to find this correct combo. If we can do this , then its easy to get the middle elements and thus the
        median
        How can we find this combination ?? 

        Lets take another example to understand better
        a = 8,12,19,23,31,33 b=2,9,17,29,30,32 n1=5,n2=6 -> n1+n2=11
        combined sorted array: 2,8,9,12,17,19,23,29,30,31,32,33
        No. of elements needed to be picked to find median = (n+1)/2 = 6
        median = (19+23)/2
        So in this case we need to pick 2 elements to find the median since we have even total no. of elements. 
        Lets apply BS on array a
        l = 0 -> minimum no. of elements that we can pick from a 
        r = n1 -> maximum no. of elements that we can pick from a
        1) l=0,r=6 -> mid = 3 -> we need to pick 3 elements from array a -> we need to pick 6-3 elements from array b 
        so after partition the arrays look like 
        a = first_half=[8,12,19(l1)] + second_half=[(r1)23,31,33]
        b = first_half=[2,9,17(l2)] + second_half=[(r2)29,30,32]
        Notice closely the edge elements , Since we want to make a correct partition , we want all the first half of the 
        elements less than the second half of the elements in the combined array. For this to happen we need to have 
        l1<r1 (this is obvious since the array a is sorted)
        l2<r2 (this is obvious since the array b is also sorted)
        l1<r2
        l2<r1
        So the above conditions must be satisfied for the partition to be valid. 
        Here we can notice that all the conditions are valid and hence our parition is valid. 
        If our parition is valid then how can we calculate the median ??? We need to find the last element of the first half and the first 
        element of the second half since these are the middle elements for mdian calculation
        last element of the first half = max(l1,l2)
        first element of the right half =. min(r1,r2)
        median = (max(l1,l2) + min(r1,r2))/2

        1) Consider the case where the parition looks like : 
        a = [8,12,19,23] + [31,33]
        b = [2,9] + [17,29,30,32]
        Here l1>r2 -> it clearly means that we need to push 23 to the second half and include 17 in the first half so we move the right 
        pointer to mid-1 

        2) Consider the case where the partition looks like:
        a = [8,12] + [19,23,31,33]
        b = [2,9,17,29] + [30,32]
        Here l2>r1 -> This clearly means that we need to push 29 to the second half and 19 to the first half In this case,we move left pointer 
        to mid+1

        3) if we have a case where the largest element in array a is smaller than the smallest element in array b or vice 
        versa , then there is no need to do all the calculations , we can easily calculate the median.

        Sometimes we might take all elements from either a or b , In that case , it might happen that any of l1,l2,r1,r2 
        might not exist. In that case , we can take 
        l1,l2 = INT_MIN 
        and r1,r2=INT_MAX since we take maximum of l1,l2 and minimum of r1,r2

        For the odd case , we can pick the majority of the elements in the first half and calculate the median using the 
        formula 
        median = max(l1,l2) 
        */
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2; // total elements
        int no_of_elements_to_be_picked = (n+1)/2; // no. of elements to be picked from both nums1 and nums2 to find median 
        int no_of_elements_picked_from_nums1 = 0;
        int no_of_elements_picked_from_nums2 = 0;
        double ans; // final median
        // we apply BS on the smaller sized array of both
        if(n1>n2)
        {
            // we swap and call the same function again
            return findMedianSortedArrays(nums2,nums1);
        }
        else if(n1==0)
        {
            if(n2%2==0)
            return double(nums2[n2/2] + nums2[n2/2 -1])/2.0;
            else
            return double(nums2[n2/2]);
        }
        else if(n2==0)
        {
            if(n1%2==0)
            return double(nums1[n1/2] + nums1[n1/2-1])/2.0;
            else
            return double(nums1[n1/2]);
        }
        else
        {
            int l = 0; // min no. of elements that we can pick from array nums1
            int r = min(no_of_elements_to_be_picked,n1); // max no of elements that we can pick from array nums1
            /* 
            we need to find how many elements we need to pick from nums1. In other words , how many elements from nums1
            will be in the first half of the combined sorted array(of size n1+n2).
            */
            while(l<=r)
            {
                int mid = l + (r-l)/2;
                no_of_elements_picked_from_nums1 = mid; // from 0 to mid => this will always be less than n1
                no_of_elements_picked_from_nums2 = no_of_elements_to_be_picked - no_of_elements_picked_from_nums1;
                if(no_of_elements_picked_from_nums2 > n2)
                {
                    // this combination is not possible since nums2 does not have that many elements to pick from 
                    l=mid+1;
                }
                else
                {
                    int l1 = INT_MIN;
                    int l2 = INT_MIN;
                    int r1 = INT_MAX;
                    int r2 = INT_MAX;

                    // l1 , r1 calculation
                    if(no_of_elements_picked_from_nums1 == 0)
                    {
                        // l1 will not exist
                        r1 = nums1[mid];
                    }
                    else if(no_of_elements_picked_from_nums1 == n1)
                    {
                        // r1 will not exist
                        l1 = nums1[n1-1];
                    }
                    else
                    {
                        //both l1 and r1 will exist
                        l1 = nums1[mid-1];
                        r1 = nums1[mid];
                    }

                    //l2 , r2 calculation
                    if(no_of_elements_picked_from_nums2 == 0)
                    {
                        //l2 will not exist
                        r2 = nums2[0];
                    }
                    else if(no_of_elements_picked_from_nums2 == n2)
                    {
                        //r2 will not exist
                        l2 = nums2[n2-1];
                    }
                    else
                    {
                        //both will exist
                        l2 = nums2[no_of_elements_picked_from_nums2-1];
                        r2 = nums2[no_of_elements_picked_from_nums2];
                    }

                    //check the validity condition
                    if(l1<=r2 and l2<=r1)
                    {
                        //valid condition 
                        if(n%2==0)
                        ans = (double)(max(l1,l2) + min(r1,r2))/2.0;
                        else
                        ans = (double)(max(l1,l2));
                        break;
                    }
                    else if(l1>r2)
                    {
                        // we need to push l1 to the second half -> take less elements from nums1 -> move r to mid-1;
                        r = mid-1;
                    }
                    else
                    {
                        //l2>r1 -> we need to push l2 to second half -> take more elements from nums1 -> move l to mid+1
                        l=mid+1;
                    }
                }
            }
        }
        return ans;
    }
};
