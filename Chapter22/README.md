
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
The space here is the amount of space that data structure(a graph expressed as a adjacency matrix) takes place.  
To determine if $(u, v) \in E$, you only need to look at $G(u, v)$ and find if it is 0 or 1. If u = v, it takes no time.  

For faster edge lookup, adjacency-matrix ls more powerful than adjacency-list  at the cost of useing asymtotically more memory.  

## Exercises & Problems

## Codes

## References
