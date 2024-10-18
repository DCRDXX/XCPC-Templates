//AC自动机
// 求有多少个不同的模式串在文本串中出现过，两个模式串不同当且仅当题面编号不同O(文本串长度 + 模式串总长度)
int nex[1000005][26],cnt;
int exist[1000005];
int fail[1000005];
int add()
{
    ++cnt;
    memset(nex[cnt],0,sizeof(nex[cnt]));
    exist[cnt] = 0;
    fail[cnt] = 0;
    return cnt;
}
void init()
{
    cnt = -1;
    add();
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
    exist[cur]++;
}
void getfail()
{
    queue<int> q;
    for(int i = 0;i < 26;i++)
    {
        if(nex[0][i])
        {
            fail[nex[0][i]] = 0;
            q.push(nex[0][i]);
        }
    }
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0;i < 26;i++)
        {
            if(nex[now][i])
            {
                fail[nex[now][i]] = nex[fail[now]][i];
                q.push(nex[now][i]);
            }
            else
                nex[now][i] = nex[fail[now]][i];
        }
    }
}
int query(string s)
{
    int now = 0;
    int ans = 0;
    for(int i = 0;i < s.size();i++)
    {
        now = nex[now][s[i] - 'a'];
        for(int j = now;j && exist[j] != -1;j = fail[j]) // exist打标记，trie上走过的点不再走
        {
            ans += exist[j];
            exist[j] = -1;
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    getfail();
    string s;
    cin >> s;
    cout << query(s);

}  



// AC自动机求每个模式串在文本串中出现次数 O(文本串长度 + 模式串总长度)
int nex[200005][26],cnt;
int exist[200005];
int fail[200005];
int in[200005];
int dp[200005];
int ans[200005];
int add()
{
    ++cnt;
    memset(nex[cnt],0,sizeof(nex[cnt]));
    exist[cnt] = 0;
    fail[cnt] = 0;
    return cnt;
}
void init()
{
    cnt = -1;
    add();
}   
void insert(string s,int i)
{
    int cur = 0;
    for (auto it : s)
    {
        if(!nex[cur][it - 'a'])
            nex[cur][it - 'a'] = add();
        cur = nex[cur][it - 'a'];
    }
    exist[cur] = i;
}
void getfail()
{
    queue<int> q;
    for(int i = 0;i < 26;i++)
    {
        if(nex[0][i])
        {
            fail[nex[0][i]] = 0;
            in[fail[nex[0][i]]]++;
            q.push(nex[0][i]);
        }
    }
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0;i < 26;i++)
        {
            if(nex[now][i])
            {
                fail[nex[now][i]] = nex[fail[now]][i];
                in[fail[nex[now][i]]]++;
                q.push(nex[now][i]);
            }
            else
                nex[now][i] = nex[fail[now]][i];
        }
    }
}

void query(string s)
{
    int now = 0;
    for(int i = 0;i < s.size();i++)
    {
        now = nex[now][s[i] - 'a'];
        dp[now]++;
    }
}
map<string,int> mp;
string s[200005];
int pos = 0;
void topu()
{
    queue<int> q;
    for(int i = 1;i <= cnt;i++)
    {
        if(!in[i])
            q.push(i);
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        ans[exist[x]] = dp[x];
        int to = fail[x];
        in[to]--;
        dp[to] += dp[x];
        if(!in[to])
            q.push(to);
    }
}
void solve()
{
    init();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        if(!mp.count(s[i]))
            mp[s[i]] = ++pos;
        insert(s[i],mp[s[i]]);
    }
    getfail();
    string s1;
    cin >> s1;
    query(s1);
    topu();
    for(int i = 1;i <= n;i++)
        cout << ans[mp[s[i]]] << "\n";
}  