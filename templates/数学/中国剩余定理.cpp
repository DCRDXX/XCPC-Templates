// 保证模数两两互质，这个函数返回的是符合方程组的最小正数解，一般要求的正是这个。在 a1 * a2 * a3 * .... * an内存在唯一解
ll CRT(int k) // k 是数组长度
{ 
    ll n = 1, ans = 0;
    for(int i=0;i<k;i++) n = n * mod[i];
    for(int i=0;i<k;i++)
    {
        ll m = n/mod[i];
        ll b,y;
        exgcd(m,mod[i],b,y);
        ans = (ans + r[i] * m  * b % n) % n;
    }
    return (ans % n + n) % n;
}