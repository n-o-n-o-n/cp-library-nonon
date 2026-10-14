# Prufer Code

$n$ 頂点の木と $\lbrace 1,2,\dots,n \rbrace^{n-2}$ に対する全単射を扱う.

```
vector<int> prufer_code_compress(vector<vector<int>> t)
```
- 木から Purufer Code を生成する
- 計算量は $O(n \log n)$

```
vector<vector<int>> prufer_code_expansion(vector<int> p)
```
- Purufer Code から木を生成する
- 計算量は $O(n \log n)$

## Reference
- https://37zigen.com/prufer-code/ 