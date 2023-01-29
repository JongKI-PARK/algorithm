
# 1. The Role of Algorithms in Computing  

To solve a large scale problem, "Data Structure" and "Efficient Algorithm" is needed. Data Structure is the way data is expressed in memory.  

<pre>
                      -------------------
                     |                   |                     
         input  ->   |     procedure     |  ->   output          
                     |                   |                     
                      -------------------
</pre>

Algorithm is ***well defined computational procedure that takes input and output***. ***"Well defined procedure"*** is important because well defined means that it is expressed ***logically***. Accoring to Turing's idea, If it is expressed logically, it can be done ***automatically***. In other words, if you want something to be done automatically, it should be well defined.  

In Turing Machine, the working procedure is expressed in the form of a *table*. Movement (state transition) between states in the table is automatic.  
| Current State | Next State | 
| --- | --- |
| | |
| | |
| | |
| | |

So, an algorithm consists of computational steps, and each computational step consists of data (parameters) and operators (functions). So, before turing, computing (algorithm) was said to be a combination of functions. The difference between defining an algorithm as a combination of functions and defining it as a table can prove that automatic processing is possible if it is defined as a table.  

<br><br>

Consequently, algorithms can (and should) solve all logical computational problems. When an algorithm is devised, it has to do two things.  
* Proof of Correctness  
* Runtime analysis should be done.  

<br><br>

The runtime for computational problems can be divided into P / NP -C.  
* What can be solved in polynomial time is P. Although these are called Efficient algorithms, there are many that have long execution times such as $n$ , $n^2$, $n^3$, $n^4$, $n^5$ ... Therefore, in reality, only algorithms up to $n^2$ are used.  
* Since NP - C algorithms are approximated to algorithms with P time, it is necessary to know a lot about algorithms with P time.
* The NP problem can be solved with the brute force method. For example, in the case of the sorting algorithm, it is enough to check whether all n! permutations of n elements have been sorted. However, the census has the potential for exponential growth. n! > $2^n$, and the number of atoms in the universe is said to be about $10^{79}$. With $10^{79}$ = (about) $2^{240}$ , you can guess that even if there are only about 240 elements in the array, it takes a lot of time to investigate with the brute force method.  
* There is no effective algorithm for NP yet. The problem of whether there is a boundary between P and NP problems is a P/NP problem.  

<br><br><br>

## References
