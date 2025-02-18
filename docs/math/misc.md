# math/misc

`main/math` にある色々なものの取扱説明書

## Berlekamp Massey
```
vector<mint> Berlekamp_Massey(vector<mint> a)
```
- 先頭が `a` の要素であるような線形漸化式の係数を求める
- 計算量は $O(n^2)$

### Verify
- https://judge.yosupo.jp/submission/236934 

### Reference
- https://37zigen.com/berlekamp-massey/ 

## Bostan Mori
```
mint Bostan_Mori(FPS p, FPS q, long long k)
```

- $[x^k]p(x)/q(x)$ を求める
- 計算量は $O(M(d)\log k)$
    - ここで $M(d)$ は $d$ 次の多項式の掛け算の計算量
    - 基本的には $O(d\log d)$ だと思っていい

### Verify
- https://judge.yosupo.jp/submission/236946

### Reference
- https://q.c.titech.ac.jp/docs/progs/polynomial_division.html
- https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a 

## BMBM
```
mint BMBM(vector<mint> x, long long k)
```
- Berlekamp Massey と Bostan Mori を合わせることで線形漸化式を持つものの先頭を naive に計算し, その第 $k$ 項を求めることができる

### Verify
- https://yukicoder.me/submissions/1012632 
