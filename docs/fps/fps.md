# FPS

形式的冪級数を扱うライブラリ.

## Constructor
```
fps<mint> f(int n)
```
- 長さ $n$ の多項式を作る
- 次数は $n-1$ であることに注意

## Operator

以下の演算子が利用できる
```
-fps

fps + mint
fps - mint
fps * mint
fps / mint

fps += mint
fps -= mint
fps *= mint
fps /= mint

fps + fps
fps - fps
fps * fps
fps / fps
fps % fps

fps += fps
fps -= fps
fps *= fps
fps /= fps
fps %= fps

fps <<=
fps >>=

fps <<
fps >>

fps(mint x)
fps(fps g)
```
- `fps(mint)` は $f$ に $x$ を代入した結果を返す
- `fps(fps g)` は $f$ と $g$ の合成を返す

## dot
```
fps dot(fps f)
```
- 自身と各点積を取ったものを返す
- 計算量は $O(n)$

## diff
```
fps diff()
```
- 微分をした結果を返す
- 計算量は $O(n)$

## integral
```
fps integral()
```
- 積分をした結果を返す
- 計算量は $O(n)$

## inv
```
fps inv()
```
- 多項式の積としての逆元を返す
- 計算量は $O(n \log n)$

## exp
```
fps exp()
```
- $\sum_{k=0}^{\infty}f^k/k!$ を返す
- 計算量は $O(n \log n)$

## log
```
fps log()
```
- `exp` の逆関数
- $\log(1-f) = - \sum_{k=1}^{\infty}f^k/k$
- 計算量は $O(n \log n)$

## pow
```
fps pow(long long k)
```
- $f^k$ を計算する
- 計算量は $O(n \log n)$
