# Relaxed Convolution

オンラインで畳み込みを行う.

## Constructor
```
relaxed_convolution<mint> RC(int n)
```
- `n` は列の長さ

## function
```
mint get(mint x, mint y)
```
- $a_k = x, b_k = y$ として $c_k = \displaystyle\sum_{i+j=k}a_ib_j$ を計算する
- 計算量はならしで $O(n \log^2 n)$
