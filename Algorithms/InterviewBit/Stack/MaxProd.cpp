int Solution::maxSpecialProduct(vector<int> &A) {
	int n = A.size();
	vector<int> LeftSpecialValue(n,0),RightSpecialValue(n,0);
	stack<int> leftCalc;
	leftCalc.push(0);
	LeftSpecialValue[0]=0;
	for(int i=1;i<n;i++){
		while(!leftCalc.empty()){
			if(A[leftCalc.top()]>A[i]) break;
			leftCalc.pop();
		}
		LeftSpecialValue[i] = (leftCalc.empty())?0:leftCalc.top();
		leftCalc.push(i);
	}
	stack<int> rightCalc;
	rightCalc.push(n-1);
	RightSpecialValue[n-1]=0;
	for(int i=n-2;i>=0;i--){
		while(!rightCalc.empty()){
			if(A[rightCalc.top()]>A[i]) break;
			rightCalc.pop();
		}
		RightSpecialValue[i] = (rightCalc.empty())?0:rightCalc.top();
		rightCalc.push(i);
	}
	long long mx = -1;
	for(int i=0;i<n;i++){
		mx=max(mx,LeftSpecialValue[i]*1LL*RightSpecialValue[i]);
	}
	return mx%1000000007;
}

int Solution::maxSpecialProduct(vector<int> &A) {
    long long int start = 0, end = 0;
    long long int ans = 0;
    long long int l = 0, r = 0;
    bool flag = true;
    for(end = 1; end < A.size()-1; end++)
    {
        if(A[start] > A[end])
        {
            l = start;
            flag = false;
        }
        if(A[end-1] > A[end])
        {
            start = end-1;
            l = start;
            flag = false;
        }
        if(flag) {
            start = start + 1;
        }
        if(A[end + 1] > A[end])
        {
            r = end + 1;
        }
        if(ans < l*r)
        {
            ans = l*r;
        }
        flag = true;
        l = r = 0;
    }
    return ans%1000000007;
}

// https://www.interviewbit.com/problems/maxspprod/