# Combination

組み合わせ関連の色々を詰め合わせたもの. 適切に前計算をして高速に動くようにしている. 基本的には素数 $\bmod$ での `mint` を用いての使用を前提にしている.

## Constructor
```
Combination<mint> C(int n = 0)
```
- `mint` は素数 $\bmod$ での `modint`
- `n` を指定すると前計算の定数倍が良くなる
- `n` を指定しなくても前計算は $O(n)$

## fac
```
mint fac(int n)
```
- $n!$ を返す
- $0! = 1$
- 計算量は $O(1)$

## finv
```
mint finv(int n)
```
- $1/n!$ を返す
- 計算量は $O(1)$

## inv
```
mint inv(int n)
```
- $1/n$ を返す
- 計算量は $O(1)$

## C
```
mint C(int n, int k)
```
- 二項係数 $_{n}\mathrm{C}_{k}=n!/(n-k)!k!$ を返す
- 計算量は $O(1)$

## multi_C
```
mint multi_C(vector<int> v)
```
- `v` の中身を $(k_i)_i$ として多項係数 $(\sum k_i)!/\prod k_i!$ を返す
- 計算量は $O(\# v)$

## P
```
mint P(int n, int k)
```
- 順列 $_{n}\mathrm{P}_{k}=n!/(n-k)!$ を返す
- 計算量は $O(1)$

## catalan
```
mint catalan(int n)
```
- カタラン数 $C_n$ を返す
- 計算量は $O(1)$

## grid_path
```
mint grid_path(int n, int m)
```
- グリッド上の経路の数え上げを行う
- 返り値は $_{n+m}\mathrm{C}_{n}$
- 計算量は $O(1)$