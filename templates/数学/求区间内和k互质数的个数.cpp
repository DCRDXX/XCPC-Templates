//求区间L R 内与k互质的数的个数
vector<int> primes;
int num = 0;
int sum = 0;
for(ll i = 2;i * i <= n;i++)
{
    if(n%i == 0)
    {
        primes.pb(i);
        while(n%i==0)
            n/=i;
    }
}
if(n > 1)
primes.pb(n);

void dfs(int pos,int mul,int len)
{
    if(pos == primes.size())
    {
        if(len)
        {
            if(len&1)
                sum += num/mul;
            else
                sum -= num/mul;
        }
        return;
    }
    dfs(pos+1,mul,len);
    dfs(pos+1,mul*primes[pos],len+1);
}
int ask(int r,int k)
{
    num = r; sum = 0;
    dfs(0,1,0);
    return r - sum;
}