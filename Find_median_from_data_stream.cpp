/*
Do this only after doing 
1) Find the median of 2 sorted arrays 
2) Find the kth element of 2 sorted arrays 

Approach-1 :- In a sorted array , we need the middle elements to get the median. Lets consider an example : 1,4,6,7 . In this case , median = (4+6)/2. So we need to make a data 
structure in such a way that , its easy to track the middle elements of the data stream when sorted.

let data stream after sorting = 1,2,3,4,5,6
Notice the first half of the sorted data stream : [1,2,3] 
Notice the second half of the sorted data stream : [4,5,6] 
If we store the first half of the elements in max heap and second half of the elements in a min heap , then we can easily calculate the median using the top elements of the heaps.

consider a data stream : 7 , 1, 3, 2 , 19 , 8 , 0 
Intially min_heap=[] and max_heap=[]
-> 7 max_heap=[7] min_heap=[]
-> 1 max_heap=[1] min_heap=[7] (since 7 belongs to the second half , it should be present in the min heap)
-> 3 max_heap=[1,3] min_heap=[7] 
-> 2 max_heap=[1,2] min_heap=[3,7] (since 2 is less than top of max heap,it belongs to the first half.So we need to move top of the max heap to min heap and then insert 2 
in max heap)
-> 19 max_heap=[1,2,3] min_heap[7,19] here since 19 is greater than the top of the min heap , it belongs to the second half and we need to push it into the min heap. 
But if we do this the no. of elements in the min_heap will increase by 1 more than the no. of elements in the max_heap. We always want to keep the no. of elements in 
the max_heap higher(one extra more) than the no. of elements in the min heap so that the median calculation in case of odd number inputs can easily be calculated only
using the max heap. We can also store directly in the min_heap also. If we do that , then for odd number of inputs , we need to check the larger size of min heap and 
max heap and return the median appropriately.
-> 8 max_heap=[1,2,3] min_heap=[7,8,19]
-> 0 max_heap=[0,1,2,3] min_heap=[7,8,19]
*/


class MedianFinder {
    priority_queue<int> pq_max; // max heap
    priority_queue<int,vector<int>,greater<int>> pq_min; // min heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(pq_max.size()==0)
        {
            pq_max.push(num);
            return;
        }
        if(pq_min.size()==0)
        {
           if(num>=pq_max.top())
           pq_min.push(num);
           else
           {
             // remove the top element from max heap, push it into min heap and insert the num into max heap
             pq_min.push(pq_max.top());
             pq_max.pop();
             pq_max.push(num);
           }
           return;
        }
        /*
        We need to maintain the elements in such a way that after sorting data stream, the first half of the elements are in the max heap 
        and the second half of the elements are in the min heap.
        */
        int left_max = pq_max.top(); // first half (left half) maximum
        int right_min = pq_min.top(); // second half (right half) minimum
        if(pq_max.size() == pq_min.size())
        {
            if(num<=right_min)
            {
                // num falls in the first half of the array -> max heap
                pq_max.push(num);
            }
            else
            {
                // num > right_top -> num falls in the second half of the array -> min heap
                // we remove the top of min heap , push it into the max heap and then insert the num into min heap
                pq_min.pop();
                pq_max.push(right_min);
                pq_min.push(num);
            }
        }
        else
        {
            /*
            pq_max and pq_min does not have equal size now -> always max_heap will have one more extra element than max heap if they are not 
            equal
            */
            if(num<=left_max)
            {
                // num belongs to the left
                // we remove the top of max heap , push it into the min heap and then insert num into max heap
                pq_max.pop();
                pq_max.push(num);
                pq_min.push(left_max);
            }
            else
            {
                // we can directly insert in the min heap since it belongs to the second half of the sorted array
                pq_min.push(num);
            }
        }
    }
    
    double findMedian() 
    {
        if(pq_max.size() == 0 and pq_min.size() == 0)
        return 0.0;
        else if(pq_max.size() == pq_min.size()) // even case
        return double(pq_max.top() + pq_min.top())/2.0;
        else
        return double(pq_max.top()); // odd case
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
