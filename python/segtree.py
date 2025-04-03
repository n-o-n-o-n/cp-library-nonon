class segtree():
    def __init__(self, v, op, e):
        self.n = len(v)
        self.op = op
        self.e = e
        self.log = 1
        while (1 << self.log) < self.n:
            self.log += 1
        self.sz = 1 << self.log
        self.d = [self.e for _ in range(2 * self.sz)]
        for i in range(self.n):
            self.d[i + self.sz] = v[i]
        for i in range(self.sz - 1, 0, -1):
            self.update(i)
    def update(self, p):
        self.d[p] = self.op(self.d[2 * p], self.d[2 * p + 1])
    def set(self, p, x):
        assert 0 <= p < self.n
        p += self.sz
        self.d[p] = x
        for i in range(1, self.log + 1):
            self.update(p >> i)
    def prod(self, l, r):
        assert 0 <= l <= r <= self.n
        l += self.sz
        r += self.sz
        pl, pr = self.e, self.e
        while l < r:
            if l & 1:
                pl = self.op(pl, self.d[l])
                l += 1
            if r & 1:
                r -= 1
                pr = self.op(self.d[r], pr)
            l >>= 1
            r >>= 1
        return self.op(pl, pr)
    def all_prod(self):
        return self.d[1]
    def max_right(self, l, f):
        assert 0 <= l <= self.n
        assert f(self.e)
        if l == self.n:
            return self.n
        l += self.sz
        p = self.e
        while True:
            while (l & 1) == 0:
                l >>= 1
            np = self.op(p, self.d[l])
            if not f(np):
                while l < self.sz:
                    l <<= 1
                    np = self.op(p, self.d[l])
                    if f(np):
                        p = np
                        l += 1
                return l - self.sz
            p = np
            l += 1
            if (l & -l) == l:
                break
        return self.n
    # todo : min_left を書く
