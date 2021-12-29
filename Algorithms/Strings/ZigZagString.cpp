string Solution::convert(string a, int b) {
    if(b==1)return a;
    vector<string> res(b);
    int i = 0, j = 0 ;
    
    // boolea variable to check if i am moving forward for the lines (res);
    bool forward = true; // initially it is true;
    
    while(i<a.length()){
        res[j] +=  a[i++];
        
        // if moving forward then make it false once we reach the end.
        if(forward) forward = !(j==b-1);
        
        // if moving backward (i.e, forward is false), then make it true once we reach in the front.
        else forward = j==0;
        
        if(forward)j++;
        else j--;
    }
    
    string ans = "";
    for(auto x: res)ans += x; // append strings line by line.
    return ans;
}

// https://www.interviewbit.com/problems/zigzag-string/