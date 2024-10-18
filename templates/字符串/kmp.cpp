// kmp 在s中找p O(n+m)
void getnext() // next[i] : p[0] 到 p[i-1] 中 最长前后缀交集(前后缀不包括整个串)
{
    next[0] = 0,next[1] = 0;
    for(int i = 1;i < p.size();i++)
    {
        int j = next[i];
        while(j && p[i] != p[j])
            j = next[j];
        if(p[i] == p[j]) next[i+1] = j+1;
        else next[i+1] = 0;
    }
}
void kmp()
{
    int j = 0;
    for(int i = 0;i < s.size();i++)
    {
        while(j && s[i] != p[j])
            j = next[j];
        if(s[i] == p[j])
            j++;
        if(j == p.size())
        {
            //匹配成功
        }
    }
}