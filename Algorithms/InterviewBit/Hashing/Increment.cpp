vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int, int> numberIndices;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(numberIndices.find(A[i])==numberIndices.end())
            numberIndices[A[i]]=i;
        else{
            A[numberIndices[A[i]]]++;
            numberIndices[A[i]+1] = numberIndices[A[i]];
            int newIndex = find(A.begin()+numberIndices[A[i]], A.begin()+i, A[i])-A.begin();
            if(newIndex<i)
                numberIndices[A[i]]=newIndex;
            else
                numberIndices[A[i]]=i;
        }
    }
    return A;
}

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    
    //map with key as the value of array element and,
    //value as min Heap for all the indexes of that element
    using minHP = priority_queue<int, vector<int>, greater<int>>;
    unordered_map<int, minHP> mp;
    
    for(int i=0 ; i<n ; i++){
        //Check if element is already present in array
        if(mp.find(A[i]) != mp.end()){
            //Take the first index of the element
            //pop the index and increment its value
            //push the found index in mp[element+1]
            int idx = mp[A[i]].top();
            mp[A[i]].pop();
            A[idx]++;
            mp[A[i]+1].push(idx);
        }
        mp[A[i]].push(i);
    }
    
    return A;
}

// https://www.interviewbit.com/problems/an-increment-problem/