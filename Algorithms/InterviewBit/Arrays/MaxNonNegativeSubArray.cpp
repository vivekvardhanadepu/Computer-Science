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

vector<int> Solution::maxset(vector<int> &A) {
    long long int max_ending_here=0, max_so_far=0;
    int max_length = 0, length = 0, max_index = 0;
    int n = A.size();
    vector<int> result;

    for(int i=0;i<n;i++){
        if(A[i]<0){
            max_ending_here = 0;
            length=0;
            continue;
        }
        max_ending_here += A[i];
        length++;
        if(max_ending_here > max_so_far){
            max_so_far = max_ending_here;
            max_length = length;
            max_index = i;
        } else if(max_ending_here == max_so_far){
            if(max_length<length){
                max_length = length;
                max_index = i;
            }
                
        }
    }

    for(int i=max_index-max_length+1;i<=max_index;i++){
        result.push_back(A[i]);
    }
    return result;
}

// https://www.interviewbit.com/problems/max-non-negative-subarray/