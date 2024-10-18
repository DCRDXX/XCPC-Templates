// 除数范围1-n  被除数 ：k 
// O(sqrt(n))
for (int l = 1,r;l <= n;l = r + 1)
{
    r = k / (k / l);
}