// 需要先预处理出fact[]，即阶乘
ll inv(ll a,ll p)
{
    return qpow(a,p-2);
}
ll C(ll m,ll n,ll p)
{
    return m < n ? 0 : fact[m] * inv(fact[n],p) % p * inv(fact[m - n],p) % p;
}
ll lucas(ll m,ll n,ll p)
{
    return n == 0 ? 1 % p : lucas(m / p,n / p,p) * C(m % p,n % p,p) % p;
}