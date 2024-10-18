// 定义矩阵
struct matrix
{
    ll x[105][105];
    matrix(){memset(x,0,sizeof(x));}
}
// 矩阵乘法 ()
matrix multiply(matrix &a,matrix &b)
{
    matrix c;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= n;k++)
                c.x[i][j] += a.x[i][k] * b.x[k][j];
        }
    }
    return c;
}
// 矩阵快速幂
matrix mksm(matrix &a,ll m)
{
    matrix res;
    for(int i = 1;i <= n;i++)
        res.x[i][i] = 1;
    while(m)
    {
        if(m&1) res = multiply(res,a);
        a = multiply(a,a);
        m = m >> 1;
    }
    return ans;
}
