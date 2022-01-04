vector<int> Solution::solve(vector<int> &A) {
    int non_negative_index = 0;
    int n = A.size();
    vector<int> result;
    for(int i=0;i<n;i++){
        if(A[i]>=0){
            non_negative_index = i;
            break;
        }
    }
    int i=non_negative_index-1, j=non_negative_index;
    for(;i>=0&&j<n;){
        if(-A[i]>A[j]){
            result.push_back(A[j]*A[j]);
            j++;
        }
        else{
            result.push_back(A[i]*A[i]);
            i--;
        }
    }
    if(i<0){
        for(;j<n;j++){
            result.push_back(A[j]*A[j]);
        }
    }
    else{
        for(;i>=0;i--){
            result.push_back(A[i]*A[i]);
        }
    }
    return result;
}

vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans(A.size());

    int left = 0;
    int right = A.size()-1;

    for(int i=A.size()-1;i>=0;--i){
        if(abs(A[left]) > abs(A[right])){
            ans[i] = A[left]*A[left];
            left++;
        }
        else{
            ans[i] = A[right]*A[right];
            right--;
        }
    }
    return ans;
}
