# Rolling Hash

文字列に対する一致判定をハッシュを用いて行うライブラリ．$10^9$ より少し大きい素数 $3$ つで判定している．

更新の有無に応じて `rolling_hash_static.hpp` と `rolling_hash_dynamic.hpp` を使い分ける．

## Constructor
```
rolling_hash R(string s)
```
- `s` に対してハッシュをとる

## set_base
```
rolling_hash::set_base(int b)
```
- ハッシュの基数を決める
- ハック対策に実行時ランダムにするといい
- 上の `Constructor` を呼び出す前に行う必要がある
- 計算量は $O(1)$

## set
```
void set(int p, char c)
```
- `s` の `p` 文字目を `c` に変更する
- `rolling_hash_dynamic.hpp` でのみ行える
- 計算量は $O(\log \lvert s \rvert)$

## prod
```
array<long long, 3> prod(int l, int r)
```
- `s` の `l` 文字目から `r-1` 文字目までのハッシュ値を返す
- 計算量は `static` なら $O(1)$，`dynamic` なら $O(\log \lvert s \rvert)$


# verify
- `static` : https://atcoder.jp/contests/abc141/submissions/59285592 
- `dynamic` : https://atcoder.jp/contests/abc331/submissions/59289698 