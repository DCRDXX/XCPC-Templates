// 树的重心 ：如果在树中选择某个节点并删除，这棵树将分为若干棵子树，统计子树节点数并记录最大值。取遍树上所有节点，使此最大值取到最小的节点被称为整个树的重心。
//sz : 树的大小 mss：最大子树大小
vector<int> ctr // 重心
void dfs(int x,int father)
{
    sz[x] = 1 , mss[x] = 0;
    for (int i = head[x];i;i = edges[i].next)
    {
        int to = edges[i].to;
        if(to!=father)
        {
            dfs(to,x);
            sz[x] += sz[to];
            mss[x] = max(mss[x],sz[to]);
        }
    }
    mss[x] = max(mss[x],n - sz[x]);
    if(mss[x] <= n/2)
    {
        ctr.push_back(x);
    }
}