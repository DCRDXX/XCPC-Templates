struct edge
{
    int to,w,next;
}edges[m];
int head[n],cnt;
void add(int from,int to,int w)
{
    edges[++cnt].w = w;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt;
}