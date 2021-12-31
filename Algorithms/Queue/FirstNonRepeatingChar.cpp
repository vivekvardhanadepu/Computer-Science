string Solution::solve(string A) {
    map<char, int> charMap;
    queue<char> charQ;
    string result="";
    for(int i=0;i<A.length();i++){
        if(charMap[A[i]]==0){
            charQ.push(A[i]);
            charMap[A[i]]=1;
        } else if(charMap[A[i]]==1){
            charMap[A[i]]=2;
        }

        while(!charQ.empty()&&charMap[charQ.front()]==2){
            charQ.pop();
        }

        if(charQ.empty())
            result+="#";
        else{
            result+=charQ.front();
        }
    }
    return result;
}


// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/