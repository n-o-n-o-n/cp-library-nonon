# Prefix Binomial Sum

$\displaystyle\sum_{i=0}^{k}\binom{n}{i}$ を適切な前計算のもと高速に求める.  
$b=400$ として $n,k$ が $b$ の倍数の部分だけ記録している. $b$ の値の最適性について具体的な評価はしてない. 実測でこれくらいが良さそうだったので $400$ とした.

クエリ先読みができる場合は Mo's Algorithm の要領で走査する方が定数倍が良いはず（これも実測）.

## Constructor
```
prefix_binomial_sum<mint>(int n)
```
- クエリを渡る $n$ の最大値を $n$ として前計算する
- 計算量は $O(bn)$

## get
```
mint get(int n, int k)
```
- 先にあげたクエリに答える
- 計算量は $O(b)$
