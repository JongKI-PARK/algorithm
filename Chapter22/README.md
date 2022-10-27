
# 22. Elementary Graph Algorithms  

Chapter22 presints methods for representing a graph G = (V + E) and for searching a graph. Searching a graph means systematically following the edges of the graph so as to visit the vertices of the graph. There are two most common computational representations of graphs : Adjacency list and Adjacency matrices.  
Both adjacency list and adjacency matrices can be used to represent directed and undirected graphs. But adjacency list is usually preferred because it provides a compact way to represent sparse graphs.(Not only in sparse graphs, but usually $|E|$ is less than $|V|^2$)  

![image](https://user-images.githubusercontent.com/97037853/198192336-56dda1b0-c40f-4c83-adf0-6e98a2cf36f7.png)  
(Source : Figure 22.1 in Introduction to Algorithms 2nd edition)  

Most of the graph algorithms in this book assume that an input graph is represented in adjacency-list form. The adjacency list representation of a graph G consists of an array which is length of the number of the vertices and each element in the array has lists of vertices adjacent to $u \in V $.  

If the graph is represented in adjacency list, 
| Space / Time | notation |
| --- | --- |
| Space | $Θ(V + E)$ |
| Time (list all vertecies adjacent to $u$) | $Θ(degree(u))$  |
| Time (determine if $(u, v) \in E$) | $O(degree(u))$ |

*Comment*  
The space here is the amount of space that data structure(a graph expressed an s an adjacency list) takes place.  
The degree(u)  

## Exercises & Problems

## Codes

## References
