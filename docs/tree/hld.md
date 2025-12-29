# Heavy Light Decomposition

木に対するパスクエリを行う. 

計算量は, HLD による計算量のみを記載しており, 実際には `SegTree` で同名の関数を呼ぶときの計算量倍される.

## Constructor
```
heavy_light_decomposition<SegTree, bool edge, bool commutative> G(int n)
```
- 頂点数 $n$ の木を HL 分解する
- `SegTree` は列に対するクエリを答える構造体で, セグ木, 遅延セグ木, Sparse Table などが想定される
    - `SegTree` 内部で, HLD から呼ぶ関数 (`set`, `prod`, `apply` など) が定義されている必要がある
    - 呼ばないもの (Point Add Path Sum のときの `apply` など) は定義されてなくても良い
- `edge` を `true` にすると辺クエリに, `false` にすると頂点クエリに答えられるようになる
- `commutative` を `true` にすると可換クエリに, `false` にすると非可換クエリに答えられるようになる
    - 具体的には, 内部で呼ぶ `prod` や `apply` の挙動が変わり, 
        - `commutative` = `true` のとき:
            - `SegTree` に対して, $l \leq r$ を満たすようにクエリが飛ぶ
        - `commutative` = `false` のとき:
            - `SegTree` に対して, $l > r$ のクエリも飛んでくる
            - このとき, `SegTree` によって $a_{r-1} \times a_{r-2} \times \cdots \times a_l$ が返されることが期待される
            - 例えば, `/src/data_structure/segtree/directed_range_query.hpp` に普通のセグ木を乗せるなどすれば良い
- 計算量は $O(n)$

## add_edge
```
void add_edge(int u, int v, S w)
```
- 頂点 $u$ と頂点 $v$ を結ぶ重み $w$ の辺を追加する
- 重みがいらないときは `add_edge(u, v)` でよい
- 計算量は $O(1)$

## set
```
void set(int u, S w)
void set(int u, int v, S w)
```
- 頂点 $u$ の重みを $w$ に変更する
- 頂点 $u$ と頂点 $v$ を結ぶ辺の重みを $w$ に変更する
- 計算量は $O(1)$

## apply
```
void apply(int u, int v, F f)
```
- 頂点 $u$ から頂点 $v$ への単純パス上の頂点 / 辺に $f$ を作用させる
    - 両端点が含まれることに注意する
- 計算量は $O(\log n)$

## get
```
S get(int u)
S get(int u, int v)
```
- 頂点 $u$ の重みを $w$ を返す
- 頂点 $u$ と頂点 $v$ を結ぶ辺の重みを返す
- 計算量は $O(1)$

## prod
```
S set(int u, int v)
```
- 頂点 $u$ から頂点 $v$ への単純パス上の頂点 / 辺の総積を（この向きで）取得する
    - 両端点が含まれることに注意する
- 計算量は $O(\log n)$
