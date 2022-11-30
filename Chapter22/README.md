
# 22. Elementary Graph Algorithms  

Chapter22 presents methods for representing a graph G = (V + E) and for searching a graph. Searching a graph means systematically following the edges of the graph so as to visit the vertices of the graph. There are two most common computational representations of graphs : Adjacency list and Adjacency matrices.  
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

For faster edge lookup, adjacency-matrix ls more powerful than adjacency-list at the cost of using asymtotically more memory.  

<br>

### BFS(Breadth-first serach)  

With graph G = (V + E) and distinguished source vertex s, BFS algorithm discovers all vertices at distance k from s before discovering any vertices at distance k + 1. Breath-first search constructs a breath-first tree, initially containing only its root, which is the source vertex s. Whenever a white vertex v is discovered in the course of scanning the adjacency list of an already discovered vertex u, the vertex v and the edge (u, v) are added to the tree. BFS algorithm below assumes that the input graph G is represented using adjacency-lists.  

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

#### BFS Analysis  
Initialization process of line 1 - 4 takes O(V). Each vertex is enqueued and dequeued at most once so the total time devoted to queue operation is $O(V)$ (Enqueuing and dequeuing takes $O(1)$ time). The adjacency list of each vertex is scanned after dequeue operation of each verteces. The sum of the lengths of all the adjacency list is $Θ(E)$. The total running time of BFS is $O(V + E)$.  

*Observation*  
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
  3 d[u] ← time
  4 for each v in Adj[u]  // Explore edge(u, v). 
  5     do if color[v] = WHITE 
  6           then π[v] ← u
  7                DFS-VISIT(v) 
  8 color[u] ← BLACK  // Blacken u; it is finished. 
  9 f[u]  // time ← time + 1
  ```

#### DFS Analysis  


*Observation*  
* The variable time is a global variable used for timestamping.  
* Every time DFS-VISIT(u) is called, vertex u becomes the root of a new tree in the depth-first forest.  
* Depth first search yields a forest of trees  
* The history of discoveries and finishings makes a well-formed expression in the sense that the parentheses are properly nested  

### Topological sort  

  ```
  TOPOLOGICAL-SORT(G) 
  1 call DFS(G) to compute finishing times f[v] for each vertex v
  2 as each vertex is finished, insert it onto the front of a linked list 
  3 return the linked list of vertices
  ```


### SCC (Strongly Connected Components)
A strongly connected component of a directed graph G = (V + E) is a maximal set of vertices $C V$ such that for every pair of vertices u and v in C, there are paths from u to v and from v to u.(both are reachable from each other.  

  ```
  STRONGLY-CONNECTED-COMPONENTS (G) 
  1 call DFS (G) to compute finishing times f[u] for each vertex u
  2 compute $$G^T$$
  3 call DFS ($G^T$), but in the main loop of DFS, consider the vertices in order of decreasing f[u] (as computed in line 1) 
  4 output the vertices of each tree in the depth-first forest formed in line 3 as a  separate strongly connected component
  ```


#### SCC Analysis

## Exercises & Problems

### 22. 1-1
> Given an adjacency-list representation of a directed graph, how long does it take to compute the out-degree of every vertex? How long does it take to compute the in-degrees?  

### 22. 1-3
> The transpose of a directed graph $G = (V, E)$ is the graph $G^T = (V, E^T)$, where $E^T = {(v, u) \in V × V : (u, v) \in E}$. Thus, $G^T$ is G with all its edges reversed. Describe efficient algorithms for computing $G^T$ from $G$, for both the adjacency-list and adjacency-matrix representations of G. Analyze the running times of your algorithms.  

### 22. 2-1
> Show the d and π values that result from running breadth-first search on the directed graph of Figure 22.2(a), using vertex 3 as the source.  ![image](https://user-images.githubusercontent.com/97037853/201806978-5d7f2f2b-4656-4de7-a6ca-5415c12cb0bc.png)  


### 22. 2-2
> Show the d and π values that result from running breadth-first search on the undirected graph of Figure 22.3, using vertex u as the source.  

### 22. 2-3
> What is the running time of BFS if its input graph is represented by an adjacency matrix and the algorithm is modified to handle this form of input?  

### 22. 2-4
> Argue that in a breadth-first search, the value d[u] assigned to a vertex u is independent of the order in which the vertices in each adjacency list are given. Using Figure 22.3 as an example, show that the breadth-first tree computed by BFS can depend on the ordering within adjacency lists.  

### 22. 2-7
> The diameter of a tree T =(V, E) is given by $\max_{u,v \in V}  \delta(u, v)$ : that is, the diameter is the largest of all shortest-path distances in the tree. Give an efficient algorithm to compute the diameter of a tree, and analyze the running time of your algorithm.  

### 22. 3-2
> Show how depth-first search works on the graph of Figure 22.6. Assume that the for loop of lines 5-7 of the DFS procedure considers the vertices in alphabetical order, and assume that each adjacency list is ordered alphabetically. Show the discovery and finishing times for each vertex, and show the classification of each edge.  ![image](https://user-images.githubusercontent.com/97037853/201806319-ab42cb07-92ce-4312-9be6-a32ddab4bfcd.png)  


### 22. 3-3
> Show the parenthesis structure of the depth-first search shown in Figure 22.4.  
![image](https://user-images.githubusercontent.com/97037853/201806611-09fb655a-7091-4c68-9c93-73deaa7b390f.png)


### 22. 3-7
> Give a counterexample to the conjecture that if there is a path from u to v in a directed graph G, and if d[u] < d[v] in a depth-first search of G, then v is a descendant of u in the depth-first forest produced.  

### 22. 3-8
> Give a counterexample to the conjecture that if there is a path from u to v in a directed graph G, then any depth-first search must result in d[v] ≤ f[u].  

### 22. 3-11  
> Show that a depth-first search of an undirected graph G can be used to identify the connected components of G, and that the depth-first forest contains as many trees as G has connected components. More precisely, show how to modify depth-first search so that each vertex v is assigned an integer label cc[v] between 1 and k, where k is the number of connected components of G, such that cc[u] = cc[v] if and only if u and v are in the same connected component.  


## Codes

## References
[1] https://stackoverflow.com/questions/11468621/why-is-the-time-complexity-of-both-dfs-and-bfs-o-v-e  

## 궁금증
* bfs분석에서 초기화 과정이 O(V)인 이유가 있나? 세타 V아닌가?  

## todo
* 
