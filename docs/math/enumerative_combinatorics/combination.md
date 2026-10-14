# Combination

組み合わせ関連の色々を詰め合わせたもの. 適切に前計算をして高速に動くようにしている. 基本的には素数 $\bmod$ での `mint` を用いての使用を前提にしている.

## combination::fac
```
combination::fac<mint>(int n)
```
- $n!$ を返す
- $0! = 1$
- 計算量は $O(1)$

## combination::finv
```
combination::finv<mint>(int n)
```
- $1/n!$ を返す
- 計算量は $O(1)$

## combination::inv
```
combination::inv<mint>(int n)
```
- $1/n\;\;\text{in }\bmod p$ を返す
- 計算量は $O(1)$

## combination::nCk
```
combination::nCk<mint>(int n, int k)
```
- 二項係数 $_{n}\mathrm{C}_{k}=n!/(n-k)!k!$ を返す
- 計算量は $O(1)$

## combination::multi_C
```
combination::multi_C<mint>(vector<int> v)
```
- `v` の中身を $(k_i)_i$ として多項係数 $(\sum k_i)!/\prod k_i!$ を返す
- 計算量は $O(\lvert v \rvert)$

## combination::nPk
```
combination::nPk<mint>(int n, int k)
```
- 順列 $_{n}\mathrm{P}_{k}=n!/(n-k)!$ を返す
- 計算量は $O(1)$

## combination::catalan
```
combination::catalan<mint>(int n)
```
- カタラン数 $C_n$ を返す
- 計算量は $O(1)$

## combination::grid_path
```
combination::grid_path<mint>(int n, int m)
```
- グリッド上の経路の数え上げを行う
- 返り値は $_{n+m}\mathrm{C}_{n}$
- 計算量は $O(1)$