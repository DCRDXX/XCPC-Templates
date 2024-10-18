ll sqrt(ll n) {
    ll lo = 0, hi = 2 * std::sqrt(n);
    while (lo < hi) {
        ll x = (lo + hi) / 2;
        if (x * x >= n) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }
    return lo;
}