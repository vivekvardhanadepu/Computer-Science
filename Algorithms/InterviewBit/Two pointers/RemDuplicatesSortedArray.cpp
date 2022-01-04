int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lastIndex=1,n=A.size(),prev=A[0];
    if(n<2)
        return n;
    for(int i=1;i<n;i++){
        if(prev!=A[i]){
            if(lastIndex!=i)
                A[lastIndex]=A[i];
            lastIndex++;
            prev=A[i];
        }
    }
    return lastIndex;
}

// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/