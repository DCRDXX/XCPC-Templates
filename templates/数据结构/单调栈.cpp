stack<int> s;
for(int i = 1;i <= n;i++)
{
    while(!s.empty()&&arr[s.top()] < arr[i])
    {
        r[s.top()] = i;
        s.pop();
    }
    s.push(i);
}
while(!s.empty())
{
    r[s.top()] = n+1;
    s.pop();
}