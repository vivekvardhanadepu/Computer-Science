/**
* Pseudo code for iterative DFS
* @Parameters: Graph G, source node s, key
*/

DFS(G, s, key):
      stack = new Stack()
      stack.push( s )            //Push s to stack 
      mark s as visited
      while ( stack is not empty):
            //Pop node from stack and start to visit its children
            v  =  stack.pop()
            
            if(v == key) return true //We found the key
            
            //Push all the unvisited neighbours of v to stack 
            for all neighbours w of v in Graph G:
                //unvisited neighbors
                if w is not visited :   
                     stack.push( w )
      return false     // If it reaches here, then all nodes have been explored 
                      //and we still havent found the key.
