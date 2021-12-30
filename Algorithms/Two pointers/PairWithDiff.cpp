int Solution::solve(vector<int> &a, int b){
    int n = a.size();
    b = abs(b);

    sort(a.begin(), a.end());
    
    for(int i1 = 0, i2 = 1; i2 < n;){
        int d = a[i2]-a[i1];
        
        if(d < b) i2++;
        else if(d > b) i1++;
        else if(i1 != i2) return 1;
        else break;
    }
    return 0;
}

int Solution::solve(vector<int> &A, int B) 
{
    int max=-99999;
    int min=99999;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]>max) max=A[i];
        if(A[i]<min) min=A[i];
    }

    int* m;
    m=(int*)malloc((max-min+1)*sizeof(int));

    if(B>max-min) return 0;
    for(int i=0;i<max-min+1;i++) m[i]=0;
    for(int i=0;i<A.size();i++)
    {
        m[A[i]-min]=1;
    }

    for(int i=0;i<A.size();i++)
    {
        if((A[i]+B<=max) && (A[i]+B>=min)) m[A[i]-min+B]++;
    }

    for(int i=0;i<max-min+1;i++)
    {
        if(B==0)
        {
            if(m[i]>2) return 1;
        }
        else
        {
            if(m[i]>1) return 1; 
        }
    }
    return 0;
}


// https://www.interviewbit.com/problems/pair-with-given-difference/