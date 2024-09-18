# Affine

- 一次関数 $ax+b$ を管理する構造体

## Constructor
```
(1) affine<mint> f()
(2) affine<mint> f(a, b)
```
- 型 `mint` を定義する必要がある
    - 基本的には `modint` を想定している
- (1) で宣言すると合成の単位元 $f(x) = x$ で初期化される
## 各種演算
```
affine(mint x)
affine(affine f)
```
が動く.
