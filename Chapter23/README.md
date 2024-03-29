
# 23. Minimum Spanning Trees

What is Minimum Spanning Tree?  
Tree is a connected acyclic graph. Spanning tree is a tree that contains all the vertices in graph G.  


In an undirected graph G = (V, E) where a weight w(u, v) of each edges are given, we wish to find an acyclic subset $T \in E$ that connects all of the vertices and whose total weight $w(T) = \Sigma_{(u, v) \in T} w(u, v)$ is minimized. Since T is acyclic and connects all of the vertices, it must form a tree, which we call a spanning tree since it "spans" the graph G. We call the problem of determining the tree T the minimum-spanning-tree problem.  


At first, the generic algorithm to find minimum spanning tree will be introduced. After ther generic algorithm, two algorithms (Kruskal, Prim algorithm) will be introduced. The two algorithms Kruskal and Prim algorithm is the specific implementation of the generic algorithm. To start with a conclusion, generic algorithm constructs a minimum spanning tree by adding safe edges one by one until the number of the edges become |V| - 1.  
Prim and kruskal algorithms differ in how they select and add safe edges to A. In Kruskal's algorithm, the set A is a ***forest***. The safe edge added to A is always a least-weight edge in the graph that connects two distinct components(trees). In Prim's algorithm, the set A forms a ***single tree***. The safe edge added to A is always a least-weight edge connecting the tree to a vertex not in the tree.  


### Generic MST algorithm  
  ```
  GENERIC-MST(G, w) 
  1 A ← Ø 
  2 while A does not form a spanning tree 
  3       do find an edge (u, v) that is safe for A
  4       A ← A ∈ {(u, v)} 
  5 return A
  ```
Here is a Generic algorithm for finding a minimum spanning tree. Generic algorithm constructs a minimum spanning tree by adding safe edges one by one. 

#### Generic MST correctness
1. Prior to each iteration, A is a subset of some minimum spanning tree.  
2. At each step, it determines an edge (u, v) which is safe.  
3. Safe edge is added to A and at each step, A is still a subset of some minimum spanning tree.  

***Terms***
* Cut : A cut (S, V - S) of an undirected graph G = (V, E) is a partition of V.  
* Crossing edge : Crossing edge (u, v) ∈ E crosses the cut (S, V - S) where u ∈ S , v ∈ V - S.  
* We say that the cut respects a set A of edges if no edge in A crosses the cut.  
* Safe edge : An edge a safe edge for A, since it can be safely added to A while maintaining the invariant.  
* Light edge : An edge is a light edge crossing a cut if its weight is the minimum of any edge crossing the cut. 


### Theorem and Corollary for Kruskal and Prim algorithm

#### Theorem (Theorem 23.1)  
Let G = (V, E) be a connected, undirected graph with a real-valued weight function w defined on E. Let A be a subset of E that is included in some minimum spanning tree for G, let (S, V - S) be any cut of G that respects A, and let (u, v) be a light edge crossing (S, V - S). Then, edge (u, v) is safe for A.

#### Corollary (Corollary 23.2)  
Let G = (V, E) be a connected, undirected graph with a real-valued weight function w defined on E. Let A be a subset of E that is included in some minimum spanning tree for G, and let $C = (V_C, E_C)$ be a connected component (tree) in the forest $G_A = (V, A)$. If (u, v) is a light edge connecting C to some other component in GA, then (u, v) is safe for A.


### Kruskal algorithm

  ```
  MST-KRUSKAL(G, w)
  1 A ← Ø 
  2 for each vertex v ∈ V[G]
  3     do MAKE-SET(v)
  4 sort the edges of E into nondecreasing order by weight w
  5 for each edge (w, v) ∈ E, taken in nondecreasing order by weight
  6     do if FIND-SET(u) ≠ FIND-SET(v)
  7           then A ← A ∈ {(u, v)} 
  8                UNION(u, v)
  9 return A
  ```


### Prim algorithm

  ```
  MST-PRIM(G, w, r) 
   1 for each u ∈ V [G] 
   2     do key[u] ← ∞
   3        π[u] ← NIL 
   4  key[r] ← 0 
   5 Q ← V [G] 
   6 while Q ≠ Ø 
   7       do u ← EXTRACT-MIN(Q) 
   8 for each v ∈ Adj[u] 
   9     do if v ∈ Q and w(u, v) < key[v] 
  10           then π[v] ← u
  11                key[v] ← w(u, v)
  ```


#### Kruskal and Prim algorithm Correctness
How can the correctness proof of generic algorithms be applied to the correctness proofs of Prim and Kruskal algorithms? 

* Remember in Kruskal's algorithm, the set A is a ***forest***. The safe edge added to A is always a least-weight edge in the graph that connects two distinct components(trees).  
1. Prior to each iteration, A is Ø and it is a subset of some minimum spanning tree.  
1-1. All the vertices becomes a tree consisting of a single vertex by MAKE-SET() operation.  
2. Edges $(u, v) \in E$ sorted in nondecreasing order by weight are retrieved sequentially, and if u and v do not belong to the same tree, the two trees are combined with the UNION() operation.  
2-1. Safe edge (u, v) for A connects distinct components(trees) in the graph since $A \cup {(u, v)}$ must be acyclic. (Theorem 23.1)
3. This process is repeated until S contains all vertices.  

* Remember in Prim's algorithm, the set A forms a ***single tree***. The safe edge added to A is always a least-weight edge connecting the tree to a vertex not in the tree.  
1. Prior to each iteration, A is consisted of a single source vertex which is a subset of some minimum spanning tree.  
1-1. Cut (S, V - S) is made where S = {r} and V - S = V -{r}. Cut (S, V - S) respects set A of edges.  
2. At each step, it determines an edge (u, v) which is safe.  
2-1. At this point, edge (u, v) is a crossing edge. It crosses the cut (S, V - S) where u ∈ S , v ∈ V - S.  
3. Safe edge is added to A and at each step, A is still a subset of some minimum spanning tree. (Corollary 23.1)  
3-1. Cut (S, V - S) is expanded to include vertex v.  
4. This process is repeated until S contains all vertices.  


## Exercises and Problems

## References
[1] https://iopscience.iop.org/article/10.1088/1757-899X/917/1/012077/pdf  

## Questions
