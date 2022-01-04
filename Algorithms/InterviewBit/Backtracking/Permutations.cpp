void permuteHelper(vector<int> &A, int index, vector<vector<int>> &result){
    int n = A.size();
    if(index == n-1){
        result.push_back(A);
        return ;
    }
    for(int i=index;i<n;i++){
        // for(int j=i+1;j<n;j++){
            swap(A[i],A[index]);
            permuteHelper(A, index+1, result);
            swap(A[i],A[index]);
        // }
    }
    return ;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> result;
    permuteHelper(A, 0, result);
    return result;
}

// https://www.interviewbit.com/problems/permutations/