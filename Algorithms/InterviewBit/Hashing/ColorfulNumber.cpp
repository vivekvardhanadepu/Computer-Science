int Solution::colorful(int A) {
    string num = to_string(A);
    unordered_map<long long, bool>hash;
    for(int i=0;i<num.length();i++) {
        long long mul = 1;
        for(int j=i;j<num.length();j++){
            mul*=(num[j]-'0');
            if(hash.find(mul)!=hash.end())
                return 0;
            hash[mul]=true;
        }
    }
    return 1;
}

// https://www.interviewbit.com/problems/colorful-number/