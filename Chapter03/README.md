
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
o(g(n)) = {f(n) : for any positive constant c > 0, there exists a constant n0 > 0 such that 0 ≤ f(n) < cg(n) for all n ≥ n0}. 

ω-notation  
ω(g(n)) = {f(n): for any positive constant c > 0, there exists a constant n0 > 0 such that 0 ≤cg(n) < f(n) for all n ≥ n0}. 
</pre>

The important thing here is "for any positive constants c > 0"  in o-notation and ω-notation. The main difference is that in f(n) = O(g(n)), the bound 0 ≤ f(n) ≤ cg(n) holds for some constant c > 0, but in f(n) = o(g(n)), the bound 0 ≤ f(n) < cg(n) holds for all constants c > 0. The asymptotic upper bound provided by O-notation may or may not asymptotically tight. The bound 2n ^2 = O(n^2) is asymptotically tight, but the bound 2n = O(n^2) is not. o-notation denote an upper bound that is not asymptotically tight. The same applies to ω-notation.  

## Exercises & Problems

### 3. 1-1
> Let f(n) and g(n) be asymptotically nonnegative functions. Using the basic definition of Θ-notation, prove that $max(f(n), g(n)) = Θ(f(n) + g(n))$. 

<ol type="i">
  <li> Because f(n) and g(n) be asymptotically nonnegative functions, $f(n) \geq 0$ and $g(n) \geq 0$ (where $n \geq n_0$).</li>
  <li> $f(n) \leq max(f(n), g(n))$ and $g(n) \leq max(f(n), g(n))$ (where $n \geq n_0$).</li>
</ol>  

From the first one, we can get $(f(n) + g(n)) \geq max(f(n), g(n))$.  
From the second one, we can get $(f(n) + g(n)) \leq 2* max(f(n), g(n))$.  

So $0 \leq c_1 * (f(n) + g(n)) \leq max(f(n), g(n)) \leq c_2 * (f(n) + g(n))$ (where $c_1 = \frac {1}{2}$ and $c_2 = 1$ , $n \geq n_0$).  

<br>

### 3. 1-2
> Show that for any real constants a and b, where b > 0, $(n + a)^b = Θ(n^b)$.


### 3. 1-4
> Is $2^{n+1} = O(2^n)$? 

Yes. There is $c_1$ and n which satisfies $2^{n+1} \leq c_1 * (2^n)$. For example, $c_1 = 2$, $n \geq n_0 = 1$.  

> Is $2^{2n} = O(2^n)$?

No. There is no $c_1$ and n which satisfies $2^{2n} \leq c_1 * (2^n)$.  

### 3. 1-7
> Prove that $o(g(n)) ∩ ω(g(n))$ is the empty set.

Proof by Contradiction.  
If $o(g(n)) ∩ ω(g(n))$ is not an empty set, there is some f(x) that $f(x) = o(g(n)) and f(x) = ω(g(n))$.  
by $f(x) = o(g(n))$, $\displaystyle\lim_{n \rightarrow \infty}{{f(n)} \over {g(n)}} = 0$.  
by $f(x) = ω(g(n))$, $\displaystyle\lim_{n \rightarrow \infty}{{f(n)} \over {g(n)}} = \infty$.  


## Codes

## References
[1] https://math.stackexchange.com/questions/367767/how-to-prove-that-nk-o2n  
[2] https://stackoverflow.com/questions/4856107/is-22n-o2n  

