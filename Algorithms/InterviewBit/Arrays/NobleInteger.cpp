int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> num_of_elements(n+1,0);

    for(int i=0;i<n;i++){
        if(A[i]>=0){
            num_of_elements[min(n,A[i])]++;
        }
    }

    int prev_sum = num_of_elements[n];
    for(int i=n-1;i>=0;i--){
        if(num_of_elements[i]){
            // num_of_elements[i]+=prev;
            if(prev_sum == i){
                // cout<<"bledy "<<i<<endl;
                return 1;
            }
            prev_sum += num_of_elements[i];
            
        }
    }
    return -1;
}
