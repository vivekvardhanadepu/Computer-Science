string Solution::solve(int A) {
    if(A==0)return "0";
    string s1="1",s2="";
    for(int i=2;i<=A;i++){
        int c=0;
        for(int j=s1.size()-1;j>=0;j--){
            int s=(s1[j]-'0')*i+c;
            c=s/10;
            s=s%10;
            s2+=(s+'0');
        }
        string s3=to_string(c);reverse(s3.begin(),s3.end());
        if(c!=0)s2+=s3;
        reverse(s2.begin(),s2.end());
        s1=s2;s2="";
    }
    return s1;
}


