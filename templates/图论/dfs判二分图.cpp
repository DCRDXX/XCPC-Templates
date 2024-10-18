bool dfs(int x,int c)
{
    color[x] = c;
    for (int i = head[x];i;i = next[i])
    {
        int to = edges[i].to;
        if(color[to])
        {
            if(color[to] == c)
                return false;
        }
        else if(!dfs(to,3 - c))
            return false;
    }
    return true;
}
bool f = true;
for (int i = 1;i <= n;i++)
{
    if(!color[i])
    {
        if(!dfs(i,1))
        {
            f = false;
            break;
        }
    }
}
if(f)
    cout << "YES";
else
    cout << "NO";