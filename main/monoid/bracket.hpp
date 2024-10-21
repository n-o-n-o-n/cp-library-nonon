#pragma once
#include <utility>
using namespace std;

struct Bracket {
    using S = pair<int, int>;
    static S op(S a, S b) {
        int cumsum = a.first + b.first;
        int cummin = min(a.second, a.first + b.second);
        return make_pair(cumsum, cummin);
    }
    static S e() { return make_pair(0, 0); }
    static S L() { return make_pair(1, 0); }
    static S R() { return make_pair(-1, -1); }
};