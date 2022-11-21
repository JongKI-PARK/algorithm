
# 24. Single Source Shortest Paths  

Path is a sequence of edges $(V_i, V_j) \in E$. The weight of the path is the sum of the weights of all the edges in the path. From the single source , single source shortest problem is to find the minimum weighted path.  



Both Bellman ford algorithm and Dijksta algorithm runtimes are neither a function of weight. They both doesn't depend on the dynamic range of the weight. This is why the BFS and DFS are not directly applicable to the shortest path problem. 
To start with a conclusion, Bellman ford algorithm and Dijksta algorithm takes O(VE) and O(V log V E) respectively. 

why negative weight needs to be considered?
: no negative physically . toll, 
if there is negative cycles? 
: 경로가 - 인 cycle을 계속 돌다보면 delta? 그러니까 전체 path의 길이가 계속 줄어들게 된다 따라서 벨만 포드 알고리즘에서 고려해야 되는 것은 - cycle을 계속 돌지 않도록 하는 것이다. (detect negative cycle) 

shortest path를 찾는 일반적인 알고지즘은 먼저 각 vertices를 초기화 해준 이후 d[v] > d[u] + w(u, v) 라면 update를 해준다. 언제까지 업데이트를 해주냐면 all edge have d[v] <= d[u] + w(u, v)가 될때까지 업데이트를 해준다. 이를 relax 한다고 한다. 물론 이것은 negative cycle 이 없을 때를 이야기 하는 것이다. 
until all edges are relaxed!! 이기 때문에 모든 edge를 체크 해야 한다. 

subpaths of a shortest path are shortest paths.
(can be proved by contradiction)

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
Q is initialized to entire set of vertices. don't know any shortest path to any vertex. Q has vertices which needs to be processed. S contains the set of vertices that we know the shortest path. this is the loop invariant of this algorithm. It is a greedy because line 5 it picks min priority from unprocessed vertices Q and claiming this min value ????
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


### Bellman ford algorithm
with negative edges and negative cycles 

problem 
: complexity could be exponential time ??? why ?/? n개의 노드에 대해 O(2^ N/2) 가 될 수 있음 -> dijkstra fixed
: will not even terminate if there is a negative cycle reachable from the source

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



#### Bellman ford anlaysis


## Exercises & Problems

## Codes

## References

## 궁금증
* why dijkstra algorithm is greedy  
* bellman ford correctness theroy 증명에서 소스에서부터 직접 v1으로 가는 경로보다 작은 경로가 있어서 (-가 포함되면 그럴수도 있음) 첫번째 에 relax 가 안된다면?
