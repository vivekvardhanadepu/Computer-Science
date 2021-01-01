/*
* edges[v][i]: adjacency list in the form of pairs 
    * i.e. edges[v][i].first contains the node to which v is connected 
    * and edges[v][i].second contains distance between v and edges[v][i].first.
*
* Q: Double ended queue
* distance: Array where distance[v]  contain the distance from the start node to v node. 
    * Initially, the distance from the source node to every other node is marked infinity.
*/
void Zero_One_BFS(int start)
{
       Deque <Integer > Q;     //Double-ended queue
       Q.push_back( start); 
       distance[start] = 0;       
       while(!Q.empty())
       {
           int v = Q.pop_front();
           for( int i = 0 ; i < edges[v].size(); i++){
               // if distance of neighbour of v from start node is greater 
               // than sum of distance of v from start node and edge weight 
               // between v and its neighbour (distance between v and its 
               //neighbour of v) ,then update it
               if(distance[edges[v][i].first] > distance[v] + edges[v][i].second ) {

                   distance[edges[v][i].first] = distance[v] + edges[v][i].second;

                   //if edge weight between v and its neighbour is 0 then push it to front of Deque 
                   if(edges[v][i].second == 0)
                   {
                       Q.push_front(edges[v][i].first);
                   }
                   // else push it at back
                   else
                   {
                       Q.push_back(edges[v][i].first);
                   }
           }
         }
      }
}
