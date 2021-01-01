vector<int> Solution::maxset(vector<int> &A) {
    long long sum=0,ans = INT_MIN;
    vector<int>a, b;
    for(auto i:A){
        if(i<0){
            sum=0, b.clear();
            continue;
        }
        sum+=i;
        b.emplace_back(i);
        if(ans<sum or (ans==sum and a.size()<b.size())){
            ans=sum;
            a = b;
        }
    }
    return a;
}

