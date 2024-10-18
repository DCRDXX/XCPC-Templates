int p[n], g[n], cnt; // p为质数集，g[i]为i的因子个数
bool inp[n];
void init(int n) {
    g[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!inp[i]) {
            p[++cnt] = i;
            g[i] = 2;
        }
        for (int j = 1; j <= cnt && i * p[j] <= n; ++j) {
            inp[i * p[j]] = true;
            if (i % p[j] == 0) {
                int t = i, o = 0;
                while (t % p[j] ==0) {t /= p[j]; ++o;}
                g[i * p[j]] = g[i] / (o + 1) * (o + 2);
                break;
            } else {
                g[i * p[j]] = g[i] * 2;
            }
        }
    }
}