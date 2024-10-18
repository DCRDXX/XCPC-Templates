// 树状数组
int t[n];
// 单点修改
void update_n(int pos,int x)
{
    for (int i = pos; i < n;i += lowbit(i))
        t[i] += x;
}
// 前n项和
int ask_n(int n)
{
    int ans = 0;
    for (int i = n;i;i -= lowbit(i))
        ans += t[i];
    return ans;
}