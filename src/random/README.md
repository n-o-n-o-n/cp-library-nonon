# これは何？
ストレステスト用の random generator. よくある入力などをランダムに作ってくれる. 特に verify とかはしていないのでバグってたらごめん. 

適当に書いてるので作問時のテストケース生成とかに使うときは自己責任でお願いします.

# 中身の説明
順番は適当. 私がよく使うものを上に書いてる. suffix に `_64` がついてるのは, ついていないものの 64-bit 整数版.

## utility
基本的な乱数生成をする. 乱数周りは詳しくないので `mt19937` を使っている. 一応実行ごとに違う数が出るようになってるはず.

- `int randint(int low, int hi)`
    - $low$ 以上 $hi$ 以下の整数をランダムに返す
    - 半開区間ではないので注意
- `randdouble(double low, double hi)`
    - $low$ 以上 $hi$ 以下の実数をランダムに返す
- `pair<int, int> randpair(int low, int hi, bool strict = false)`
    - $low$ 以上 $hi$ 以下の整数をランダムに生成し, `minmax` の順で返す
    - `strict` を `true` にすると同じ数が返らないようになる

## sequence
数列周りの生成器. 

- `vector<int> random_sequence(int n, int low, int hi)`
    - 長さ $n$ の整数列で, 各要素が $low$ 以上 $hi$ 以下のものをランダムに返す
- `vector<int> random_increasing_sequence(int n, int low, int hi, bool strict = false)`
    - 長さ $n$ の単調増加列で, 各要素が $low$ 以上 $hi$ 以下のものをランダムに返す
    - `strict` を `true` にすると狭義短調増加になる
- `vector<int> random_decreasing_sequence(int n, int low, int hi, bool strict = false)`
    - 長さ $n$ の単調減少列で, 各要素が $low$ 以上 $hi$ 以下のものをランダムに返す
    - `strict` を `true` にすると狭義短調増加になる
- `vector<int> random_permutaion(int n, int val = 0)`
    - 長さ $n$ の順列をランダムに生成する
    - $val$ は順列の最小値
- `string random_string(int n, char a, char z)`
    - 長さ $n$ の文字列をランダムに生成する
    - 各文字は ASCII コードの順で `a` 以上 `z` 以下のもの

## graph
グラフとか木とかの生成器. 返り値は各辺の両端の頂点番号(0-indexed).

- `vector<pair<int, int>> random_tree(int n)`
    - $n$ 頂点の重みなし無向木を生成する
    - Prüfer コードから復元するので生成に偏りがあるかも
- `vector<pair<int, int>> random_graph(int n, int m)`
    - $n$ 頂点 $m$ 辺の無向グラフを生成する
- `vector<pair<int, int>> random_connected_graph(int n, int m)`
    - $n$ 頂点 $m$ 辺の連結無向グラフを生成する
