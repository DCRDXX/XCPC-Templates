// manacher 
// P[i] 是以字符s[i]为中心字符的最长回文串的半径,最大的p[i]-1就是最长回文串长度,这个最长回文串在原字符串的开头位置是(i-p[i])/2;
int p[n << 1];
string s;
string s1 = "$#";
void manacher()
{
    int r = 0,c;
    for(int i = 0;i < s1.size();i++)
    {
        if(i < r) p[i] = min(p[(c << 1) - i],p[c] + c - i);
        else p[i] = 1;
        while(s1[i + p[i]] == s1[i - p[i]]) p[i]++;
        if(p[i] + i > r)
        {
            r = p[i] + i;
            c = i;
        }
    }
}

void solve()
{
    cin >> s;
    for(auto it : s)
    {
        s1 += it;
        s1 += '#';
    }
    s1 += '&';
    manacher();
    int ans = 0;
    for(int i = 0;i < s1.size();i++)
        ans = max(ans,p[i]-1);
    cout << ans;

}