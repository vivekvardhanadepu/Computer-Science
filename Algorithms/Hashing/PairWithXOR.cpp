int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int cnt = 0;
    for(int i= 0;i<A.size();i++){
        if(mp.find(A[i]^B)!=mp.end()) cnt++;
        else mp[A[i]]++;
    }
    return cnt;
}

// https://www.interviewbit.com/problems/pairs-with-given-xor/