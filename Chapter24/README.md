
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

Dijkstra's algorithm



## Exercises & Problems

## Codes

## References
