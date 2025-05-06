# Directed Range Query

非可換なクエリに対して逆向きの積も取れるようにする構造体. HLD に非可換クエリを載せるとき以外の使い道が不明.

## Constructor
```
directed_range_query<SegTree> drq(int n)
directed_range_query<SegTree> drq(vector<M> v)
```
- `SegTree` には `segtree` や `lazy_segtree` を載せればいい
- あとは載せたものと同じ関数が使えるようになる (はず)