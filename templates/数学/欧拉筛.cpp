//欧拉筛 
// 每个合数只被他的最小质因子筛掉 
// (快速找到每个数最小质因子)
bool isnp[n];
vector<ll> primes;
void init(ll n)
{
    isnp[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (!isnp[i])
            primes.push_back(i);
        for (ll it : primes)
        {
            if (it * i > n)
                break;
            isnp[it * i] = 1;
            if (i % it == 0)
                break;
        }
    }
}