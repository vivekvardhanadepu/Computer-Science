vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int dir = 0;
    vector<int> B;
    int m = A.size();
    int n = A[0].size();
    int t=0, l=0, b = m-1, r=n-1;
    while(t<=b && l<=r){
        if(dir==0){
            for(int i=l; i<=r; i++){
                B.push_back(A[t][i]);
            }
            t++;
            dir=1;
        }
        else if(dir==1){
            for(int i=t; i<=b; i++){
                B.push_back(A[i][r]);
            }
            r--;
            dir=2;
        }
        else if(dir==2){
            for(int i=r; i>=l; i--){
                B.push_back(A[b][i]);
            }
            b--;
            dir=3;
        }
        else if(dir==3){
            for(int i=b; i>=t; i--){
                B.push_back(A[i][l]);
            }
            l++;
            dir=0;
        }
        else break;
    }
    return B;
}

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    int i=0, j=0, dir=0;
    vector<int> result;
    if(m==1)
        return A[0];
    else if(n==1){
        for(;i<m;i++)
            result.push_back(A[i][0]);
        return result;
    }
    while(i<m/2 && j<n/2){
        if(dir==0){
            for(int k=j;k<n-j;k++)
                result.push_back(A[i][k]);
            dir=1;
        }else if(dir==1){
            for(int k=i+1;k<m-i;k++)
                result.push_back(A[k][n-j-1]);
            dir=2;
        }else if(dir==2){
            for(int k=n-2-j;k>=j;k--)
                result.push_back(A[m-1-i][k]);
            dir=3;
        }else{
            for(int k=m-2-i;k>i;k--)
                result.push_back(A[k][j]);
            dir=0;
            i++;j++;
        }
    }
    if(m<=n && i==((m-1)/2)){
        for(int k=j;k<n-j;k++)
                result.push_back(A[i][k]);
    }else if(n<m && j==((n-1)/2)){
        for(int k=i;k<m-i;k++)
            result.push_back(A[k][n-j-1]);
    }
    return result;
}

// https://www.interviewbit.com/problems/spiral-order-matrix-i/
