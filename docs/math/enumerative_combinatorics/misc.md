# math/misc

`main/math/enumerative_combinatorics` にある色々なものの取扱説明書

## Partition
```
vector<mint> partition(int n)
```
- $k=0,1,\dots,n$ に対して $k$ の分割数を求める
- オイラーの五角数定理を用いて $O(n \log n)$

### Verify
- https://judge.yosupo.jp/submission/259008

### Reference
- https://ei1333.github.io/luzhiled/snippets/math/partition.html 

## Power Sum
```
vector<mint> power_sum(int k, long long n)
```
- $i=0,1,\dots,k$ に対して $\sum_{m=0}^{n}m^i$ を列挙する
- 計算量は $O(k \log k)$

### Verify
- https://atcoder.jp/contests/oupc2023-day1/submissions/58286621

### Reference
- https://maspypy.com/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%83%BB%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0-%E9%AB%98%E9%80%9F%E3%81%AB%E8%A8%88%E7%AE%97%E3%81%A7%E3%81%8D%E3%82%8B%E3%82%82%E3%81%AE#toc34 

## Subset Sum
```
vector<mint> subset_sum(vector<int> a, int m, bool neg = false)
```
- $\prod_{k \in a}(1 + x^k)$ を $m$ 次まで計算する
- `neg` を `true` にすると $\prod_{k \in a}(1 - x^k)$ の計算をする
- 計算量は $O(\# a + m \log m)$

### Verify
- https://atcoder.jp/contests/abc267/submissions/61242031 