vector<int> lps(string str){
    int M = str.length();
    vector<int> lps(M);
    int len = 0;
    lps[0] = 0;
    
    int i = 1;
    while(i < M){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int Solution::solve(string A) {
    string temp = A;
    reverse(temp.begin(), temp.end());
    string concat = A + "$" + temp;
    vector<int> lpsx = lps(concat);
    return A.length() - lpsx.back();
}

// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/