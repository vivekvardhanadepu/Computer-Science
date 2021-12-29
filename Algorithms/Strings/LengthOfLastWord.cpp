int Solution::lengthOfLastWord(const string A) {
    int n=(int)A.size(),i, nonSpace=-1;
    for(i=n-1;i>=0;i--)
        if(A[i]!=' ')
            break;
    nonSpace = i;
    for(;i>=0;i--)
        if(A[i]==' ')
            break;
    if(nonSpace==-1)
        return 0;
    return nonSpace-i;
}

// https://www.interviewbit.com/problems/length-of-last-word/