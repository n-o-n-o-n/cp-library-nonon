# Bracket

括弧列が正しい括弧列かどうかをセグ木に載せるモノイド．区間積が $(0,0)$ のとき，かつそのときに限り正しい括弧列． 

## map
```
bracket::map(char c)
```
- `c` が `(` か `)` に合わせて `pair<int, int>` を返す

# Verify
- https://atcoder.jp/contests/abc223/submissions/59311934 
