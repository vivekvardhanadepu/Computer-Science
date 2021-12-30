int Solution::solve(vector<int> &A, int B) {
 int n=A.size();
    int l=0, i=0, count=0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            count++;
        }
        while(count>B){
            if(A[l]==0)count--;
            l++;
        }
        ans=max(ans, i-l+1);
    }
    return ans;
}

// https://www.interviewbit.com/problems/maximum-ones-after-modification/