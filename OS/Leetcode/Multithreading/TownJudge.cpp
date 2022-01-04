class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustedBy(n,0);
        // vector<bool> trusts(n, false);
        for(int i=0;i<trust.size();i++){
            int a = trust[i][0];
            int b = trust[i][1];
            trustedBy[b-1]++;
            // trusts[a-1]=true;
            trustedBy[a-1]--;
        }
        for(int i=0;i<n;i++){
            if(trustedBy[i]==n-1)
                return i+1;
        }
        return -1;
    }
};

// https://leetcode.com/problems/find-the-town-judge/