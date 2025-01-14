# これは何？
ストレステスト用の random generator. よくある入力などをランダムに作ってくれる. 特に verify とかはしていないのでバグってたらごめん. 

適当に書いてるので作問時のテストケース生成とかに使うときは自己責任でお願いします.

# 中身の説明
順番は適当. 私がよく使うものを上に書いてる.

## utility
基本的な乱数生成をする. 乱数周りは詳しくないので `mt19937` を使っている. 一応実行ごとに違う数が出るようになってるはず.

- `int randint(int low, int hi)`
    - `low` 以上 `hi` 以下の整数をランダムに返す
    - 半開区間ではないので注意
- `ll randint_64(ll low, ll hi)`
    - `randint` の 64-bit 整数版
- `pair<int, int> randpair(int low, int hi, bool strict = false)`
    - `low` 以上 `hi` 以下の整数をランダムに生成し, `minmax` の順で返す
    - `strict` を `true` にすると同じ数が返らないようになる
- `pair<ll, ll> randpair_64(ll low, ll hi, bool strict = false)`
    - `randpair` の 64-bit 整数版


## sequence
数列周りの生成器. 

- `vector<int> random_sequence(int n, int low, int hi)`
    - 長さ `n` の整数列で, 各要素が `low` 以上 `hi` 以下のものをランダムに返す
- `vector<ll> random_sequence_64(int n, ll low, ll hi)`
    - `random_sequence` の 64-bit 整数版
- `vector<int> random_increasing_sequence(int n, int low, int hi, bool strict = false)`
    - 長さ `n` の単調増加列で, 各要素が `low` 以上 `hi` 以下のものをランダムに返す
    - `strict` を `true` にすると狭義短調増加になる
- `vector<ll> random_increasing_sequence_64(int n, ll low, ll hi, bool strict = false)`
    - `random_increasing_sequence` の 64-bit 整数版
- `vector<int> random_decreasing_sequence(int n, int low, int hi, bool strict = false)`
    - 長さ `n` の単調増加列で, 各要素が `low` 以上 `hi` 以下のものをランダムに返す
    - `strict` を `true` にすると狭義短調増加になる
- `vector<ll> random_decreasing_sequence_64(int n, ll low, ll hi, bool strict = false)`
    - `random_decreasing_sequence` の 64-bit 整数版
- `vector<int> random_permutaion(int n, int val = 0)`
    - 長さ `n` の順列をランダムに生成する
    - `val` は順列の最小値

## graph
グラフとか木とかの生成器. 返り値は各辺の両端の頂点番号(0-indexed).

- `vector<pair<int, int>> random_tree(int n)`
    - `n` 頂点の重みなし無向木を生成する
    - `prufer_code` から復元するので生成に偏りがあるかも

- `vector<pair<int, int>> random_graph(int n, int m)`
    - `n` 頂点 `m` 辺の無向グラフを生成する

- `vector<pair<int, int>> random_connected_graph(int n, int m)`
    - `n` 頂点 `m` 辺の連結無向グラフを生成する
