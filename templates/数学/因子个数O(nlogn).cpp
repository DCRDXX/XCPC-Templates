// g[i] 代表i的因子个数
for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
        g[j]++;
    }
}