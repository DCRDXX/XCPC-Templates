//区间筛 筛[a,b)内的质数
int primes0[1000005],primes1[1000005];
ll prime[1000005];
int cnt = 0;
void segement_sieve(ll a,ll b)
{
    for(ll i = 0;i * i < b;i++) primes0[i] = 1;
    for(ll i = 0;i < b-a;i++) primes1[i] = 1;
    for(ll i = 2;i * i < b;i++)
    {
        if(primes0[i])
        {
            for(ll j = 2 * i;j * j < b;j += i) primes0[j] = 0;
            for(ll j = max(2ll,(a + i - 1) / i) * i;j < b;j += i) primes1[j-a] = 0; 
        }
    }
    for(ll i = 0;i < b-a;i++)
    {
        if(primes1[i]) prime[++cnt] = i+a;
    }
}