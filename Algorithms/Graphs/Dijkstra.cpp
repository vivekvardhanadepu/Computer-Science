Dijkstra_Algorithm(source, G):
    """
    parameters: source node--> source, graph--> G
    return: List of cost from source to all other nodes--> cost
    """
    unvisited_list = []			// List of unvisited verticesvertices
    cost = []
    cost[source] = 0              // Distance (cost) from source to source will be 0
    for each vertex v in G:       // Assign cost as INFINITY to all vertices
       if v ≠ source
             cost[v] = INFINITY
             add v to unvisited_list    // All nodes pushed to unvisited_list initially

    while unvisited_list is not empty:        	     // Main loop
       v = vertex in unvisited_list with min cost[v]      // v is the source node for first iteration
       remove v from unvisited_list		            // Marking node as visited 

       for each neighbor u of v:			// Assign shorter path cost to neigbour u
          cost_value = Min( cost[u], cost[v] + edge_cost(v, u)]
          cost[u] = cost_value            		// Update cost of vertex u 

    return cost
