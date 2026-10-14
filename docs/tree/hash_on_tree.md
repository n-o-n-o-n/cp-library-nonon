# Hash on Tree

根付き木の同型判定を行う. $\bmod$ として

$$m_1 = 1000274903, m_2 = 1000274927,m_3 = 1000274953$$

をとり, それぞれについて

$$h(v) = \prod_{c \in \text{Child}_v}(h(c) + r_{d+1}) \bmod m_i$$

をハッシュとして用いている. ここで, $d$ は $v$ の深さ, $r$ はランダムに生成される列である.

## Constructor
```
hash_on_tree G(int n, int r)
```

## function
```
void hash_on_tree::set_base(int b)
```
- 基数を割り当てる
- 実行時にランダムで決めるといい

```
void add_edge(int u, int v)
```
- 辺 $(u,v)$ を追加する
- 計算量は $O(1)$

```
array<long long, 3> get_hash(int u)
```
- $u$ を根とする部分木のハッシュを返す
- 計算量は $O(1)$

## todo
- 全方位木 DP をさせる