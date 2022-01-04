int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int max_sum = INT_MIN;
    int sum = 0;
    for(int j=0;j<B;j++)
        sum+=A[j];
    for(int i=1;i<B+1;i++){
        
        // cout<<sum<<"naansense"<<endl;
        sum-=A[(n+B-i)%n];
        sum+=A[(n-i)%n];
        // for(int j=0;j<B;j++)
        //     sum+=A[(n+j-i)%n];
        // cout<<sum<<"bledy yell"<<endl;
        if(sum>max_sum)
            max_sum = sum;
    }
    return max_sum;
}
