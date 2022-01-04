int Solution::solve(vector<int> &A) 
{
    stack<int> S;
    int root = INT_MIN;
    for(int i = 0; i<A.size(); i++)
    {
        if(A[i] < root)
            return false;
        while(!S.empty() && A[i] > S.top())
        {
            root = S.top();
            S.pop();
        }
        S.push(A[i]);
    }
    return true;
}

// https://www.interviewbit.com/problems/valid-bst-from-preorder/