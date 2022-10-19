
# 3. Growth of Functions  

The order of growth of the running time of an algorithm gives a simple characterization of the algorithm's efficiency and also allows us to compare the relative performance of alternative algorithms. For large enough inputs, the multiplicative constants and lower-order terms of an exact running time are dominated by the effects of the input size itself.  
The notations we use to describe the asymptotic running time of an algorithm are defined in terms of functions whose domains are the set of natural numbers N = {0, 1, 2, ...}. I will show briefly about five notations (Θ-notation, O-notation, Ω-notation, o-notation, ω-notation).  

<pre>
Θ-notation  
Θ(g(n)) = {f(n) : there exist positive constants c1, c2, and n0 such that 0 ≤ c1 g(n) ≤ f(n) ≤ c2 g(n) for all n ≥ n0}.

O-notation  
O(g(n)) = {f(n): there exist positive constants c and n0 such that 0 ≤ f(n) ≤ cg(n) for all n ≥ n0}.

Ω-notation  
Ω(g(n)) = {f(n): there exist positive constants c and n_0 such that 0 ≤ cg(n) ≤ f(n) for all n ≥ n0}. 

o-notation  
o(g(n)) = {f(n) : for any positive constant c > 0, there exists a constant n0 > 0 such that $0 ≤ f(n) < cg(n) for all n ≥ n0}. 

ω-notation  
ω(g(n)) = {f(n): for any positive constant c > 0, there exists a constant n0 > 0 such that 0 ≤cg(n) < f(n) for all n ≥ n0}. 
</pre>

The important thing here is "for any positive constants c > 0"  in o-notation and ω-notation. The main difference is that in f(n) = O(g(n)), the bound 0 ≤ f(n) ≤ cg(n) holds for some constant c > 0, but in f(n) = o(g(n)), the bound 0 ≤ f(n) < cg(n) holds for all constants c > 0. The asymptotic upper bound provided by O-notation may or may not asymptotically tight. The bound 2n ^2 = O(n^2) is asymptotically tight, but the bound 2n = O(n^2) is not. o-notation denote an upper bound that is not asymptotically tight. The same applies to ω-notation.  

## Exercises & Problems

> 
## Codes

## References
[1] https://math.stackexchange.com/questions/367767/how-to-prove-that-nk-o2n  
[2] https://stackoverflow.com/questions/4856107/is-22n-o2n  
[3] 
