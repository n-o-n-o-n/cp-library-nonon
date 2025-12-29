# Centaroid Decomposition

次のように再帰的に定義される重心木を管理する.

- 根は木の中心
- 子の集合は, 根を削除してできる各部分木の重心

## Constructor
```
centaroid_decomposition G(int n)
centaroid_decomposition G(vector<vector<int>> G)
```

## function
```
void add_edge(int u, int v)
```
- 辺 $(u,v)$ を追加する
- 計算量は $O(1)$
- 辺を $n-1$ 本追加した段階で, 内部で `build` が呼ばれる
- `build` の計算量は $O(n \log n)$

```
int level(int u)
```
- 重心木における頂点 $u$ の深さを返す
- 計算量は $O(1)$

```
int sub_size(int u)
```
- 重心木における頂点 $u$ の部分木の大きさを返す
- 計算量は $O(1)$

```
int parent(int u)
```
- 重心木における頂点 $u$ の親を返す(根の場合は $-1$)
- 計算量は $O(1)$
