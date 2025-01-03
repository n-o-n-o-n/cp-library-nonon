# FPS

形式的冪級数を扱うライブラリ.

## Constructor
```
Formal_Power_Series<mint> f(int n)
```
- 長さ $n$ の多項式を作る
- 次数は $n-1$ であることに注意

## Operator

以下の演算子が利用できる
```
-FPS

FPS + mint
FPS - mint
FPS * mint
FPS / mint

FPS += mint
FPS -= mint
FPS *= mint
FPS /= mint

FPS + FPS
FPS - FPS
FPS * FPS
FPS / FPS
FPS % FPS

FPS += FPS
FPS -= FPS
FPS *= FPS
FPS /= FPS
FPS %= FPS

FPS <<=
FPS >>=

FPS <<
FPS >>

FPS(mint x)
```
- `FPS(mint)` は `f` に `x` を代入した結果を返す

## dot
```
FPS dot(FPS f)
```
- 自身と各点積を取ったものを返す
- 計算量は $O(n)$

## diff
```
FPS diff()
```
- 微分をした結果を返す
- 計算量は $O(n)$

## integral
```
FPS integral()
```
- 積分をした結果を返す
- 計算量は $O(n)$

## inv
```
FPS inv()
```
- 多項式の積としての逆元を返す
- 計算量は $O(n \log n)$

## exp
```
FPS exp()
```
- $\sum_{k=0}^{\infty}f^k/k!$ を返す
- 計算量は $O(n \log n)$

## log
```
FPS log()
```
- `exp` の逆関数
- $\log(1-f) = - \sum_{k=1}^{\infty}f^k/k$
- 計算量は $O(n \log n)$

## pow
```
FPS pow(long long k)
```
- $f^k$ を計算する
- 計算量は $O(n \log n)$

# Reference
- https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0-%e9%ab%98%e9%80%9f%e3%81%ab%e8%a8%88%e7%ae%97%e3%81%a7%e3%81%8d%e3%82%8b%e3%82%82%e3%81%ae
- https://nyaannyaan.github.io/library/fps/ntt-friendly-fps.hpp
- https://ei1333.github.io/library/math/fps/formal-power-series-friendly-ntt.hpp

# Verify
- `*`: https://judge.yosupo.jp/submission/259646
- `inv`: https://judge.yosupo.jp/submission/259647
- `exp`: https://judge.yosupo.jp/submission/259648
- `log`: https://judge.yosupo.jp/submission/259649
- `pow`: https://judge.yosupo.jp/submission/259650