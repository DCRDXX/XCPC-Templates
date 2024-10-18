//SOSDP(子集和DP) x二进制长度为t dp[x] 从 x 的所有二进制子集转移过来

for(int i = 0;i < t;i++)
{
    for(int j = 0;j < (1 << t);j++)
    {
        if(j >> i & 1)
        {
            dp[j] += dp[j ^ (1 << i)];
        }
    }
}