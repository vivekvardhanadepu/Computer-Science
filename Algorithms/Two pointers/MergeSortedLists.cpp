void Solution::merge(vector<int> &A, vector<int> &B)
{
    
    // O(1) space
    // If all elements of B are placed in array
    // then elements of A are already in place
    
    int i = A.size() - 1; // i pointing to last index of A
    int j = B.size() - 1; // j pointing to last index of B
    
    int lastPos = A.size() + B.size() - 1; // lastPos pointing to last index of merged array A and B
    
    A.resize(A.size() + B.size());
    
    while(j >= 0)
    {
        if(i >= 0 and A[i] > B[j])
            A[lastPos--] = A[i--];
        else
            A[lastPos--] = B[j--];
    }
    
}

// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/