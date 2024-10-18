//(空间开：总字符个数 * 字符集大小)
int nex[MAXN][26],cnt;
int exist[MAXN];
void init()
{
    cnt = -1;
    add();
}
int add()
{
    ++cnt;
    memset(nex[cnt],0,sizeof(nex[cnt]));
    exist[cnt] = 0;
    return cnt;
}
void insert(string s)
{
    int cur = 0;
    for (auto it : s)
    {
        if(!nex[cur][it - 'a'])
            nex[cur][it - 'a'] = add();
        cur = nex[cur][it - 'a'];
    }
    // exist[cur] = 1;
}
ll find_pre(string s)
{
    int cur = 0;
    for (auto it : s)
    {
        if(!nex[cur][it - 'a'])
            return false;
        cur = nex[cur][it - 'a'];
    }
    return exist[cur];
}