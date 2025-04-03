#pragma once

template<typename Monoid>
struct dual_monoid {
    using S = pair<typename Monoid::S, typename Monoid::S>;
    static S op(const S &a, const S &b) {
        return make_pair(Monoid::op(a.first, b.first), Monoid::op(a.second, b.second));
    }
    static S e() {
        return make_pair(Monoid::e(), Monoid::e());
    }
};