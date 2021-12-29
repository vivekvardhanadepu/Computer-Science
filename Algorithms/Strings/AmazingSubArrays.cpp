int Solution::solve(string A) {
    int n= A.size();
    transform(A.begin(),A.end(),A.begin(),::tolower);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u')
        {
            count=(count+(n-i))%10003;
        }
    }
    return count;
}

// https://www.interviewbit.com/problems/amazing-subarrays/
// caveat: you need to remove duplicates (: