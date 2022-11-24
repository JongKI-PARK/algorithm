
# 24. Single-Source Shortest Paths  

Path is a sequence of edges $(V_i, V_j) \in E$. The weight of the path is the sum of the weights of all the edges in the path. From the single source, single source shortest problem is to find the minimum weighted path. Two algorithms Bellman-Ford and Dijkstra's algorithm will be introduced in this chapter. Bellman-Ford algorithm solves the single-source shortest paths in the general case in which edges can have negative weight. Dijkstra's algorithm require the graph where the edge weights to be nonnegative.  


Shortest path finding algorithms in this chapter use the technique of ***relaxation***. . For each vertex $v \in V$, it maintains an attribute d[v], which is an upper bound on the weight of a shortest path from source s to v. We can say that d[v] is a shortest-path estimate. The process of relaxing an edge (u, v) consists of testing whether we can improve the shortest path to v found so far by going through u and, if so, updating d[v] and π[v]. A relaxation step may decrease the value of the shortest-path estimate d[v] and update v's predecessor field π[v]. π[v] should be updated through this algorithm to figure out not only the shortest path weight but also the paths($<V_1, V_2, ... V_k>$) to each vertices. After the process of the algorithm, π values produce shortest-paths tree.  

  ```
  RELAX(u, v, w) 
  1 if d[v] > d[u] + w(u, v) 
  2    then d[v] ← d[u] + w(u, v) 
  3         π[v] ← u
  ```

Bellman-Ford and Dijkstra algorithm which are two different algorithm finding a shortest path from a single source differ in how many times they relax each edge and the order in which they relax edges. In Dijkstra's algorithm and the shortest-paths algorithm for directed acyclic graphs, each edge is relaxed exactly once. In the Bellman-Ford algorithm, each edge is relaxed many times.  


### Bellman ford algorithm
Bellman-Ford algorithm solves the single-source shortest paths in the general case in which edges can have negative weight. It returns boolean value indicating if there is a negative cycle reachable from the source vertex s. If there is such a cycle, the algorithm indicates that no solution exists. If there is no such cycle, the algorithm produces the shortest paths and their weights.  

  ```
  BELLMAN-FORD(G, w, s) 
  1 INITIALIZE-SINGLE-SOURCE(G, s) 
  2 for i ← 1 to |V[G]| - 1 
  3     do for each edge $(u, v) \in E[G]$ 
  4            do RELAX(u, v, w) 
  5 for each edge $(u, v) \in E[G]$ 
  6     do if d[v] > d[u] + w(u, v) 
  7           then return FALSE 
  8 return TRUE 
  ```

#### Correctness
not only correctly compute shortest path but also detect negative cycles

1. Theory 
if G contains no negative cycles, after belman ford executes, d[v] 는 델타 (u,v)가 될 것이다. 

proof by induction
think of a path p from s = v0 to vk (if k is not less than |V - 1| then there is a cycle.)
this path p is a unique shortest path with a minimum number of edges 
after 1 pass through all of the edges E, we have d[v1] = delta(s, v1) because we relax edge (v0,v1) during this pass 
after k pass through all of the edges E, we have d[vk] = delta(s, vk) 
after |V - 1| passes, all reachable vertices have delta values.  


2. Corrolary 
If a value d[v] fails to converge after V -1 passes, there exsists negative weight cycles reachable from s.

if there is a repeated vertex in the path


#### Bellman ford analysis
O(VE)


### Dijkstra's algorithm

  ```
  DIJKSTRA(G, w, s) 
  1 INITIALIZE-SINGLE-SOURCE(G, s) 
  2 S ← Ø 
  3 Q ← V[G] 
  4 while Q ≠ Ø 
  5       do u ← EXTRACT-MIN(Q) 
  6          S ← $S \cup {u}$ 
  7          for each vertex $v \in Adj[u]$ 
  8              do RELAX(u, v, w)
  ```
Q has vertices which needs to be processed. S contains the set of vertices that we know the shortest path. this is the loop invariant of this algorithm. It is a greedy because line 5 it picks min priority from unprocessed vertices Q and claiming this min value ????
every loop takes different vertex from Q and moves it to S
Q is a priority queue and the priorities are d[] values

#### Dijkstra analysis
theta (V) inserts all the vertices into priority queue
theta (V) extract min operation
theta (E) decrease/update operations in priority queue (relax)

if array is used as a priority queue 
extract min operation takes theta(V)
decrease key takes theta(1)
overall theta (V * V + E * 1) = theta(V^2) 

if binary min heap is used as a priority queue
extract min operation takes theta(log V)
decrease key takes theta(log V)
overall theta(V log V + E log V)

if fibonacci heap is used ,
extract min operation takes theta(lg V)
decrease key takes theta(1)
overall theta (V * lg V + E * 1) = theta(V lgV + E) 


## Exercises & Problems

## Codes

## References
[1] https://stackoverflow.com/questions/13159337/why-doesnt-dijkstras-algorithm-work-for-negative-weight-edges  
[2] https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/  


## 궁금증
* why dijkstra algorithm is greedy  
* bellman ford correctness theroy 증명에서 소스에서부터 직접 v1으로 가는 경로보다 작은 경로가 있어서 (-가 포함되면 그럴수도 있음) 첫번째 에 relax 가 안된다면?
* problem 
: complexity could be exponential time ??? why ?/? n개의 노드에 대해 O(2^ N/2) 가 될 수 있음 -> dijkstra fixed
: will not even terminate if there is a negative cycle reachable from the source
* 이게무슨말일까

Both Bellman ford algorithm and Dijksta algorithm runtimes are neither a function of weight.  
They both doesn't depend on the dynamic range of the weight. This is why the BFS and DFS are not directly applicable to the shortest path problem. 
To start with a conclusion, Bellman ford algorithm and Dijksta algorithm takes O(VE) and O(V log V E) respectively.  
* 왜 bellman ford algorithm 은 각 vertex 를 우선순위 큐에서 뽑지 않는가
