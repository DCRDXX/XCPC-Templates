vector<int> prim;
int vis[n];
int ans[n],query[n],num[n]; // ans[i] 为 i 的因子和
void euler()//筛法求因子和
{
    ans[1] = 1;
    for(int i = 2;i < n;i++)
    {
        if(!vis[i])
        {
            prim.push_back(i);
            num[i] = ans[i] = i + 1;
        }
        for(int j = 0 ; j < prim.size() && prim[j] <= n / i; j++)
        {
            vis[i*prim[j]] = 1;
            if(i%prim[j]==0)
            {
                num[prim[j] * i] = num[i] * prim[j] + 1;
                ans[prim[j] * i] = ans[i]/num[i]*num[prim[j] * i];
                break;
            }
            else
            {
                ans[prim[j]*i] = ans[i]*(1 + prim[j]);
                num[prim[j]*i] = prim[j] + 1;
            }
        }
    }
}