int Solution::solve(string A) {
    stack<char> charStack;
    for(int i=0;i<A.length();i++){
        if(A[i]=='(')
            charStack.push(A[i]);
        else{
            if(charStack.empty())
                return 0;
            charStack.pop();
        }
    }
    if(charStack.empty())
        return 1;
    else
        return 0;
}

// https://www.interviewbit.com/problems/balanced-parantheses/