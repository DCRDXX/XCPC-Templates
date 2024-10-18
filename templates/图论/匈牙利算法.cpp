// 一个二分图中的最大匹配数等于这个图中的最小点覆盖数。
int M , N; // M,N分别表示左右两侧集合的元素数量
int Map[n][n]; // 链接矩阵存图
int p[n]; // 记录当前右侧元素所对应的左侧元素
bool vis[n] // 记录右侧元素是否已被访问过

bool match(int i)
{
    for (int j = 1;j <= N;j++)
    {
        if(Map[i][j] && !vis[j])
        {
            vis[j] = true;
            if(p[j] == 0 || match(p[j]))
            {
                p[j] = i;
                return true;
            }
        }
    }
    return false;
}
int Hungarian()
{
    int cnt = 0;
    for (int i = 1;i <= M;i++)
    {
        memset(vis,0,sizeof(vis));
        if(match(i))
            cnt++;
    }
    return cnt;
}