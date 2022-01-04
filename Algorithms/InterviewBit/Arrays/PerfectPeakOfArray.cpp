int Solution::perfectPeak(vector<int> &A) {
  int n= A.size();
  vector<int> prefix(n);
  vector<int > suffix(n);
  
  prefix[0]= A[0];

  for(int i=1;i<A.size();i++){
      prefix[i]= max(prefix[i-1], A[i]);
  }
  suffix[n-1]= A[n-1];
  for(int i= n-2;i>=0;i--){
      suffix[i]= min(suffix[i+1], A[i]);
  }
    
  for(int i=1;i<=n-2;i++){
      if(prefix[i-1]<A[i] && A[i]<suffix[i+1]){
          return 1;
      }
  }
    return 0;
}

// Using map further decreases the time complexity
int Solution::perfectPeak(vector<int> &A) 
{


    unordered_set<int> a;
    int max = A[0];
    for(int i=1;i<A.size();i++){
        if(A[i]>max){
            max = A[i];
            a.insert(i);
        }
    }
    int min = A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--){
        if(A[i]<min){
            min = A[i];
            if(a.find(i)!= a.end()){
                return 1;
            }
        }
    }
    
    
    
return 0;
}
