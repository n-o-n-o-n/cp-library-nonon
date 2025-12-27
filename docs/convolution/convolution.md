# Convolution
```
vector<mint> convolution(vector<mint> f, vector<mint> g)
```

- 畳み込みをする
- `mint::mod()` は NTT-Friendly である必要がある
- 計算量は $O((n + m) \log (n + m))$

# Arbitrary Mod Convolution
```
vector<mint> arbitrary_mod_convolution(vector<mint> f, vector<mint> g)
```

- 任意 $\bmod$ 畳み込みをする
- 計算量は $O((n + m) \log (n + m))$
- `convlution` よりも定数倍が悪い

# Middle Product
```
vector<mint> middle_product(vector<mint> f, vector<mint> g)
```

- $c_k = \displaystyle\sum_{i-j=k}a_ib_j$ を求める
- 返り値の長さは $n$
- 計算量は $O((n + m) \log (n + m))$

# Bitwise And Convolution
```
vector<mint> bitwise_and_convolution(vector<mint> f, vector<mint> g)
```
- $c_k = \displaystyle\sum_{i \;\text{and}\; j = k}a_ib_j$ で定まる $c$ を計算する
- $\lvert a \rvert = \lvert b \rvert = 2^k$ を満たす必要がある
- 計算量は $O(n \log n)$

# Bitwise Or Convolution
```
vector<mint> bitwise_or_convolution(vector<mint> f, vector<mint> g)
```
- $c_k = \displaystyle\sum_{i \;\text{or}\; j = k}a_ib_j$ で定まる $c$ を計算する
- $\lvert a \rvert = \lvert b \rvert = 2^k$ を満たす必要がある
- 計算量は $O(n \log n)$

# Bitwise Xor Convolution
```
vector<mint> bitwise_xor_convolution(vector<mint> f, vector<mint> g)
```
- $c_k = \displaystyle\sum_{i \;\text{xor}\; j = k}a_ib_j$ で定まる $c$ を計算する
- $\lvert a \rvert = \lvert b \rvert = 2^k$ を満たす必要がある
- 計算量は $O(n \log n)$

# Lcm Convolution
```
vector<mint> lcm_convolution(vector<mint> f, vector<mint> g)
```
- $c_k = \displaystyle\sum_{\text{lcm}(i,j) = k}a_ib_j$ で定まる $c$ を計算する
- $\lvert a \rvert = \lvert b \rvert$ を満たす必要がある
- $c_0$ は ill-defined であることに注意する
- 計算量は $O(n \log n)$

# Gcd Convolution
```
vector<mint> gcd_convolution(vector<mint> f, vector<mint> g)
```
- $c_k = \displaystyle\sum_{\text{gcd}(i,j) = k}a_ib_j$ で定まる $c$ を計算する
- $\lvert a \rvert = \lvert b \rvert$ を満たす必要がある
- $c_0$ は ill-defined であることに注意する
- 計算量は $O(n \log n)$
