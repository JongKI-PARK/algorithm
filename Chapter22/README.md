
# 22. Elementary Graph Algorithms  

Chapter22 presints methods for representing a graph G = (V + E) and for searching a graph. Searching a graph means systematically following the edges of the graph so as to visit the vertices of the graph. There are two most common computational representations of graphs : Adjacency list and Adjacency matrices.  
Both adjacency list and adjacency matrices can be used to represent directed and undirected graphs. But adjacency list is usually preferred because it provides a compact way to represent sparse graphs.(Not only in sparse graphs, but usually $|E|$ is less than $|V|^2$)  

![image](https://user-images.githubusercontent.com/97037853/198192336-56dda1b0-c40f-4c83-adf0-6e98a2cf36f7.png)  
(Source : Figure 22.1 in Introduction to Algorithms 2nd edition)  

Most of the graph algorithms in this book assume that an input graph is represented in adjacency-list form. The adjacency list representation of a graph G consists of an array which is length of the number of the vertices and each element in the array has lists of vertices adjacent to $u \in V $.  

If the graph is represented in ***adjacency list***, 
| Space / Time | notation |
| --- | --- |
| Space | $Θ(V + E)$ |
| Time (list all vertecies adjacent to $u$) | $Θ(degree(u))$  |
| Time (determine if $(u, v) \in E$) | $O(degree(u))$ |

*Comment*  
* The space here is the amount of space that data structure(a graph expressed as a adjacency list) taken up in memory.  
* The degree(u) is the number of vertices(nodes) adjacent to $u$.  
* To determine if $(u, v) \in E$, the upper bound of the elements to be examined is degree(u).  
* To represent a weighted graph as an adjacency list, add a weight field to each list.  

A potential disadvantage of the adjacency-list representation : The only way to check whether a given edge (u, v) is on the graph is to check the array Adj[u].  

<br>  

If the graph is represented in ***adjacency matrix***,  
| Space / Time | notation |
| --- | --- |
| Space | $Θ(V^2)$ |
| Time (list all vertecies adjacent to $u$) | $Θ(V)$  |
| Time (determine if $(u, v) \in E$) | $O(1)$ |

*Comment*  
* The space here is the amount of space that data structure(a graph expressed as a adjacency matrix) takes place.  
* To determine if $(u, v) \in E$, you only need to look at $G(u, v)$ and find if it is 0 or 1. If u = v, it takes no time.  

For faster edge lookup, adjacency-matrix ls more powerful than adjacency-list  at the cost of useing asymtotically more memory.  

<br>

### BFS(Breadth-first serach)  

With graph G = (V + E) and distinguished source vertex s, BFS algorithm discovers all vertices at distance k from s before discovering any vertices at distance k + 1. Breath-first search constructs a breath-first tree, initially containing only its root, which is the source vertex s. Whenever a white vertex v is discovered in the course of scanning the adjacency list of an already discovered vertex u, the vertex v and the dege (u, v) are added to the tree. BFS algorithm below assumes that the input graph G is represented using adjacency-lists.  

  ```
  BFS(G, s) 
   1 for each vertex u in V[G] - {s} 
   2     do color[u] <- WHITE 
   3        d[u] <- ∞
   4        π[u] <- NIL 
   5 color[s] <- GRAY 
   6 d[s] <- 0 
   7 π[s] <- NIL 
   8 Q <- Ø 
   9 ENQUEUE(Q, s) 
  10 while Q ≠ Ø 
  11      do u <- DEQUEUE(Q) 
  12         for each v in Adj[u] 
  13             do if color[v] = WHITE 
  14                   then color[v] <- GRAY 
  15                        d[v] <- d[u] + 1 
  16                        π[v] <- u
  17                        ENQUEUE(Q, v) 
  18          color[u] <- BLACK
  ```

Initialization process of line 1 - 4 takes O(V). Each vertex is enqueued and dequeued at most once so the total time devoted to queue operation is $O(V)$ (Enqueuing and dequeuing takes $O(1)$ time). The adjacency list of each vertex is scanned after dequeue operation of each verteces. The sum of the lengths of all the adjacency list is $Θ(E)$. The total running time of BFS is $O(V + E)$.  

#### Observation
* The total running time of BFS is $O(V + E)$ because it cannot reach to unconnected nodes starting from vertex $s$. In other words, in the case of BFS, it may not be possible to reach all nodes in the graph unless all nodes in the graph are connected to each other.  
* The enqueue order follows the (arbitrary) order in the graph's adjacency list, but after enqueue it is fifo order.  
* In BFS, the distance values of the nodes in the queue are at most two. (It cannot be more than three.)  

<br>

### DFS(Depth-first search)  
Unlike BFS, DFS doesn't need the source vertex as ap parameter. Furthermore, unlike breath-first search, whose predecessor subgraph sorms a tree, the predecessor subgraph produced by a depth-first search may be composed of several trees, because the search may be repeated from multiple sources.  
Depth-first search *timestamps* each vertex. Each vertex has two timestamps : the first timestamp $d[v]$ records when v is first discovered and the second timestamp $f[v]$ records when the search finishes examining v's adjacency list. These timestamps are integers between 1 and $2|V|$, since there is one discovery event and one finishing event for each of the $|V|$ vertices.  

  ```
  DFS(G) 
  1 for each vertex u in V [G] 
  2     do color[u] ← WHITE 
  3        π[u] ← NIL 
  4 time ← 0 
  5 for each vertex u in V [G] 
  6     do if color[u] = WHITE 
  7           then DFS-VISIT(u) 

  DFS-VISIT(u) 
  1 color[u] ← GRAY  // White vertex u has just been discovered. 
  2 time ← time + 1 
  3 d[u] time
  4 for each v in Adj[u]  // Explore edge(u, v). 
  5     do if color[v] = WHITE 
  6           then π[v] ← u
  7                DFS-VISIT(v) 
  8 color[u] BLACK  // Blacken u; it is finished. 
  9 f[u]  // time ← time +1
  ```


## Exercises & Problems

## Codes

## References

## 궁금증
* bfs분석에서 초기화 과정이 O(V)인 이유가 있나? 세타 V아닌가?  
