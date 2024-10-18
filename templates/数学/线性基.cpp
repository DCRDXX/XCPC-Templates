// 线性基
int cnt = 0; //如果线性基大小小于原数组大小，说明能构造出来异或为0的子集
void ins(ll x)  //构造线性基
{
    for(int i = 60;i >= 0;i--)
    {
        if(x >> i & 1)
        {
            if(!p[i])
            {
                p[i] = x;
                cnt++;
                break;
            }
            else
                x ^= p[i];
        }
    }
}

ll ask(ll x) //查询元素x能否被异或出来
{
    for(int i = 60;i >= 0;i--)
        if(x >> i & 1) x ^= p[i];
    return x == 0;
}
ll askma() // 查询异或最大值
{
    ll ans = 0;
    for(int i = 60;i >= 0;i--)
        if((ans ^ p[i]) > ans) ans ^= p[i];
    return ans;
}
ll askmi() // 查询异或最小值(记得特判0)
{
    if(zero) return 0;
    for(int i = 0;i <= 60;i++)
    {
        if(p[i])
            return p[i];
    }

}
void rebuild() //重新构造，方便查询异或第k小
{
    cnt = 0;
    for(int i = 60;i >= 0;i--)
    {
        for(int j = i-1;j >= 0;j--)
        {
            if(p[i] >> j & 1)
                p[i] ^= p[j];
        }
    }
    for(int i = 0;i <= 60;i++)
    {
        if(p[i])
            d[cnt++] = p[i];
    }
}
ll kth(ll k) //找异或第k小(记得特判0)
{
    if(k >= (1ll << cnt)) return -1; // 找不到
    ll ans = 0;
    for(int i = 60;i >= 0;i--)
        if(k >> i & 1) ans ^= d[i];
    return ans;
}
