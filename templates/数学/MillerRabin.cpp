//MillerRabin O(logn) 判断一个数是不是素数
srand((unsigned)time(NULL));
ll ksm(ll a,ll b,ll m)
{
    a %= m;
    ll ans = 1;
    while(b)
    {
        if(b&1) ans = (LL)ans * a % m;
        a = (LL)a * a % m;
        b = b >> 1;
    }
    return ans;
}
bool Miller_Rabin(ll p) {  // 判断素数
  if (p < 2) return 0;
  if (p == 2) return 1;
  if (p == 3) return 1;
  ll d = p - 1, r = 0;
  while (!(d & 1)) ++r, d >>= 1;  // 将d处理为奇数
  for (ll k = 0; k < 10; ++k) {
    ll a = rand() % (p - 2) + 2;
    ll x = ksm(a, d, p);
    if (x == 1 || x == p - 1) continue;
    for (int i = 0; i < r - 1; ++i) {
      x = (LL)x * x % p;
      if (x == p - 1) break;
    }
    if (x != p - 1) return 0;
  }
  return 1;
}