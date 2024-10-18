// a > b;
// ax0 + by0 = gcd(a,b);
// 如果参数为负数,同余方程是在模意义下的，取参数在模意义下的最小正数即可。
// ax + by = c 的一个特解是 x1 = x0*c/gcd(a,b)  y1 = y0*c/gcd(a,b);
// dx = b/gcd(a,b) dy = a/gcd(a,b);
// 通解是 x = x1 + s*dx  y = y1 - s*dy;
// 考虑x,y均为正数 L = ceil(-x1+1,dx) <= s <= floor(y1-1,dy) = R;
// 如果L > R,则不存在正整数解
// 否则,存在正整数解,解的个数是R - L + 1,s = L 时可以得到xmin,ymax ,s = R时可以得到xmax,ymin;(取模)
// 判断一个数k是否在gcd过程中出现if(a % b == k % b && k <= a)
// x的最小正整数解 x = (x1 % dx + dx)%dx;
// x的最大负整数解 x = 模数 - x的最小正整数解
ll exgcd(ll a,ll b,ll &x0,ll &y0)
{
    if(b == 0)
    {
        x0 = 1;
        y0 = 0;
        return a;
    }
    ll d = exgcd(b,a%b,y0,x0);
    y0 -= (a / b) * x0;
    return d;
}//求出 x0,y0

ll inv(ll a,ll p)
{
    ll x,y;
    if(exgcd(a,p,x,y) != 1)
        return -1;
    return (x % p + p) % p;
}