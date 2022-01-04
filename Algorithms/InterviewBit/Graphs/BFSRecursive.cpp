/**
* Pseudo code for recursive BFS
* @Parameters: Graph G represented as adjacency list, 
*  Queue q, boolean[] visited, key
* Initially q has s node in it.
*/

recursiveBFS(Graph graph, Queue q, boolean[] visited, int key){
    if (q.isEmpty())
        return "Not Found";

    // pop front node from queue and print it
    int v = q.poll();
    if(v==key) return "Found";

    // do for every neighbors of node v
    for ( Node u in graph.get(v))
    {
        if (!visited[u])
        {
            // mark it visited and push it into queue
            visited[u] = true;
            q.add(u);
        }
    }
    // recurse for other nodes
    recursiveBFS(graph, q, visited, key);
}

Queue q = new Queue();
q.add(s);
recursiveBFS(graph, q, visited, key);

