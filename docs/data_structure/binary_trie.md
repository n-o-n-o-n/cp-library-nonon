# binary_trie

整数を bit 列のように見てトライ木のように管理するデータ構造. c++ の `set` と同様の管理をしている. 

## Constructor
```
binary_trie<T> BT
```
- `binary_trie` を作る
- 整数型 `T` を定義する必要がある
    - 以降 `T` の二進数での桁数を $d$ とする
        - `T` $=$ `int` の場合は $d=31$
        - `T` $=$ `long long` の場合は $d=63$

## track
```
vector<int> track(T x)
```
- `x` が通るノードの index の列を返す
- 存在しない場合は `-1` が入る
- 計算量は $O(d)$

## insert
```
vector<int> insert(T x)
```
- `BT` に `x` を挿入する
- `x` がすでに含まれている場合は何もしない
- 計算量は $O(d)$

## erase
```
void erase(T x)
```
- `BT` から `x` を削除する
- `x` が含まれていない場合は何もしない
- 計算量は $O(d)$

## contain
```
bool contain(T x)
```
- `x` が `BT` に含まれているかどうかを `bool` 値で返す
- 計算量は $O(d)$

## kth_smallest
```
T kth_smallest(int k, T xor_val)
```
- `BT` に含まれる数に `xor_val` と xor を取って得られる集合の要素のうち `k` 番目に小さいもの（0-index）を返す
    - `xor_val` は指定しなければ $0$
    - 実際に xor をとるわけではない
- 計算量は $O(d)$

## kth_largest
```
T kth_largest(int k, T xor_val)
```
- `BT` に含まれる数に `xor_val` と xor を取って得られる集合の要素のうち `k` 番目に大きいもの（0-index）を返す
    - `xor_val` は指定しなければ $0$
    - 実際に xor をとるわけではない
- 計算量は $O(d)$

## min
```
T min(T xor_val)
```
- `BT` に含まれる数に `xor_val` と xor を取って得られる集合の最小値を返す
    - `xor_val` は指定しなければ $0$
    - 実際に xor をとるわけではない
- 計算量は $O(d)$

## max
```
T max(T xor_val)
```
- `BT` に含まれる数に `xor_val` と xor を取って得られる集合の最大値を返す
    - `xor_val` は指定しなければ $0$
    - 実際に xor をとるわけではない
- 計算量は $O(d)$

## mex
```
T max(T xor_val)
```
- `BT` に含まれる数に `xor_val` と xor を取って得られる集合の $\text{mex}$ を返す
    - `xor_val` は指定しなければ $0$
    - 実際に xor をとるわけではない
- 計算量は $O(d)$


# verify
- https://judge.yosupo.jp/submission/254068 
- https://atcoder.jp/contests/abc234/submissions/60402426
- https://www.acmicpc.net/source/87110142
- https://www.acmicpc.net/source/87109590
