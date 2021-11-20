// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <bits/stdc++.h>
using namespace std;

// utility function to form edge between two vertices
// source and dest
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool BFS(vector<int> adj[], int src, int dest, int n, vector<vector<int>> &dist)
{
    bool visited[n];
    queue<int> q;
    q.push(src);
    int level = 0;
    while (!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            int f = q.front();
            dist[src][f] = level;
            dist[f][src] = level;
            if (f == dest)
                return;
            q.pop();
            visited[f] = true;
            for (auto j = adj[f].begin(); j != adj[f].end(); j++)
                if (!visited[*j])
                    q.push(*j);
        }
        level++;
    }
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void printShortestDistance(vector<int> adj[], int src,
                           int dest, int n, vector<vector<int>> &dist)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    // int pred[v];

    BFS(adj, src, dest, n, dist);

    // vector path stores the shortest path
    if (dist[src][dist] % 2)
        cout << "Road" << endl;
    else
        cout << "Town" << endl;
}

// Driver program to test above functions
int main()
{
    // no. of vertices
    int n, q;
    cin >> n;
    cin >> q;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int n1, n2;
        cin >> n1;
        cin >> n2;
        add_edge(adj, n1 - 1, n2 - 1);
    }
    // array of vectors is used to store the graph
    // in the form of an adjacency lis
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < q; i++)
    {
        int source, dest;
        cin >> source;
        cin >> dest;
        printShortestDistance(adj, source - 1, dest - 1, n, dist);
    }
    return 0;
}
