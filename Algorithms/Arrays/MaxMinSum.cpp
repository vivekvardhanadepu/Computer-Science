int Solution::solve(vector<int> &A) {
    
    return *max_element(A.begin(),A.end()) + *min_element(A.begin(),A.end());
    
}

int Solution::solve(vector<int> &A) {
    int max=A[0], min= A[0], n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]>max){
            max = A[i];
        }
        else if(A[i]<min){
            min = A[i];
        } 
    }
    return min+max;
}
