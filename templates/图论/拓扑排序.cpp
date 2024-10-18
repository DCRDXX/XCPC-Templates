int in[n],arr[n] // in:入度 arr是排序后的数组
bool topu(int n)
{
    int cnt = 0;
    queue<int> q;
    for (int i = 1;i <= n;i++)
    {
        if(in[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        arr[++cnt] = tmp;
        for(int i = head[tmp];i;i = edges[i].next)
        {
            int to = edges[i].to;
            in[to]--;
            if(!in[to])
                q.push(to);
        }
    }
    return cnt == n;
}