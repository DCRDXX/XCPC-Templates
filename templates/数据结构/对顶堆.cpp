if(a[i] > q1.top()) q2.push(a[i]);
else q1.push(a[i]);
while((int)q1.size() - (int)q2.size() > 1)
{
    q2.push(q1.top());
    q1.pop();
}            
while((int)q2.size() > (int)q1.size())
{
    q1.push(q2.top());
    q2.pop();
}