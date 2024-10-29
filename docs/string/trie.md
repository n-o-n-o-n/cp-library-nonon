# Trie

トライ木．実装では `size` として文字の種類数を渡す実装にしているが，基本的に文字列での利用を想定している．

## Constructor
```
trie<size, base> T
```
- 文字の種類数 $\sigma = $ `size`，一文字目の文字コード `base` を渡す必要がある
    - 例えば，英小文字からなる文字列を扱うときは `trie<26, 'a'>` となる

## insert
```
vector<int> insert(string s)
```
- 文字列 `s` を挿入する
- 返り値は `s` の通るノードの index の列
- 計算量は $O(\sigma \lvert s \rvert)$

## operator []
```
string [int k]
```
- `k` 番目に挿入した文字列を返す
- 計算量は返る文字列を $s$ として $O(\lvert s \rvert)$

## kth_smallest
```
string kth_smallest(int k)
```
- 挿入した文字列のうち `k` 番目に小さいもの（0-index）を返す
- 計算量は返る文字列を $s$ として $O(\sigma \lvert s \rvert)$

## count
```
int count(string s)
```
- 挿入した文字列のうち，`s` と一致するものの個数を返す
- 計算量は $O(\lvert s \rvert)$

## count_prefix
```
int count(string s)
```
- 挿入した文字列のうち，`s` の prefix であるものの個数を返す
- 計算量は $O(\lvert s \rvert)$

## count
```
int count(string s)
```
- 挿入した文字列のうち，`s` を prefix に持つものの個数を返す
- 計算量は $O(\lvert s \rvert)$

# verify
- https://atcoder.jp/contests/abc268/submissions/59256924