// 欧拉函数 (小于等于n的正整数中与n互质的个数)
int phi(int n) // 求单个点的欧拉函数 O(sqrt(n))
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res = res * (i - 1) / i;
            while(n%i==0) n/=i;
        }       
    }
    if(n>1) res = res * (n - 1) / n;
    return res;
}
void phi() // 求1-n的欧拉函数 O(n)
{
    phi[1] = 1;
    int cnt = 0;
    for(ll i = 2;i <= n;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            prime[cnt++] = i;
            phi[i] = i-1;
        }
        for(int j = 0;j < cnt;j++)
        {
            if(i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}