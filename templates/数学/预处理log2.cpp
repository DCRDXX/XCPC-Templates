for (int i = 1;i <= n;i++)
{
    lg[i] = lg[i-1] + (1 << (lg[i-1] + 1) == i);
}