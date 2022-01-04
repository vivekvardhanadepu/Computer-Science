bool is_present(map<int,vector<int>>&m,vector<bool>&vis,int src,int dst)
{
    if(src==dst)
    {
        return true;
    }
    vis[src]=true;
    for(auto it:m[src])
    {
        if(!vis[it])
        {
            if(is_present(m,vis,it,dst))
            {
                return true;
            }
        }
    }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B)
{
    map<int,vector<int>>m;
    for(auto it:B)
    {
        m[it[0]].push_back(it[1]);
    }
    vector<bool>vis(A+1,false);
    return is_present(m,vis,1,A);
}
