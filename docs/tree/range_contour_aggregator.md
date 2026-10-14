# Range Contour Aggregator
木 $t$ に対する次のクエリを処理する. ただし, $M$ は可換モノイドとする.

- 頂点 $u$ の値を $x \in M$ に更新する
- 頂点 $u$ からの距離が $l$ 以上 $r$ 未満の頂点全体に対する積を計算する

計算量は, Range Contour Aggregator による計算量のみを記載しており, 実際には `SegTree` で同名の関数を呼ぶときの計算量倍される.

## Constructor
```
range_contour_aggregator<SegTree> t(int n)
```
- $n$ 頂点の木を作る
- `SegTree` は可換モノイドを載せたセグ木

## add_edge
```
void add_edge(int u, int v)
```
- 頂点 $u$ と頂点 $v$ を結ぶ辺を追加する
- 計算量は $O(1)$

## set
```
void set(int u, S x)
```
- 頂点 $u$ から根方向に $k$ 進んだ頂点を聞くクエリを投げる
- 計算量は $O(\log n)$

## get
```
S get(int u)
```
- 頂点 $u$ の乗っている値を返す
- 計算量は $O(1)$

## prod
```
S prod(int u, int l, int r)
```
- 頂点 $u$ から $l$ 以上 $r$ 未満の距離にある頂点全体の積を返す
- 計算量は $O(\log n)$
