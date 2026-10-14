# Min Plus Convolution (Convex, Arbitrary)
```
vector<T> min_plus_convolution(vector<T> f, vector<T> g)
```

- $c_k = \text{min}_{i + j = k}(a_i+b_j)$ で定まる $c$ を計算する
- $a$ は凸, すなわち, $2a_i \geq a_{i-1} + a_{i + 1}$ を満たす必要がある
- 計算量は $O((n + m) \log m)$
