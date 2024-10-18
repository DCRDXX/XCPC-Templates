fac[0] = 1;
for (int i = 1;i <= 1000;i++)
    fac[i] = (fac[i-1] * i) % mod;
ifac[1000] = ksm(fac[1000], mod - 2);
for (int i = 1000; i >= 1; i--)
    ifac[i - 1] = ifac[i] * i % mod;
ll C(int n, int m)
{
    if (n < m || m < 0)return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

ll A(int n, int m)
{
    if (n < m || m < 0)return 0;
    return fac[n] * ifac[n - m] % mod;
}