/**
* Pseudo code for iterative BFS
* @Parameters: Graph G, source node s, boolean[] visited, key
*/

iterativeBFS(Graph graph, int s, boolean[] visited, int key){
    // create a queue neeeded for BFS
    Queue q = Queue();

    // mark source node as discovered
    visited[s] = true;

    // push source node into the queue
    q.add(s);

    // while queue isnt empty
    while (!q.isEmpty())
    {
        // pop front node from queue and print it
        v = q.poll();
        if(v==key) return "Found";

        // for every neighboring node of v
        for (int u : graph.get(v)) {
            if (!visited[u]) {
                // mark it visited and enqueue to queue
                visited[u] = true;
                q.add(u);
            }
        }
    }
    //If key hasnt been found
    return "Not Found";
}


