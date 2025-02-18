# Biconnected Components

グラフを二重連結成分分解する. LowLink とは独立させてある.

## Constructor
```
Biconnected_Component G(int n)
```
- $n$ 頂点のグラフを構築する

## function
```
void add_edge(int u, int v)
```
- 頂点 $u$ と頂点 $v$ を結ぶ辺を追加する
- 自己ループは許されていないことに注意

```
vector<vector<int>> components()
```
- 二重連結成分分解する
- 返り値は各連結成分に含まれる辺の index
    - $i$ 番目に追加した辺を辺 $i$ としている
- 計算量は追加した変の本数を $m$ として $O(n + m)$

# verify
- https://judge.yosupo.jp/problem/biconnected_components