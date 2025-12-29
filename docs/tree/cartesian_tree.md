# Cartesian Tree
```
vector<int> cartesian_tree(vector<T> a)
```

- $a$ から誘導される Cartesian Tree における各頂点の親を返す
- $a$ の要素は distinct である必要がある
- 根の親は $-1$ とする
- 計算量は $O(n)$

# Description

Cartesian Tree とは, 各要素が distinct な列 $A$ に対し, 次のように再帰的に定義される二分木である.

- 根は $r \coloneqq \argmin A$ である.
- 左側の子は $A$ の $[1,r)$ に対し定義される Cartesian Tree の根
- 左側の子は $A$ の $(r,N]$ に対し定義される Cartesian Tree の根
