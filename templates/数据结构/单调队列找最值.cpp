//单调队列找最大值  m：区间长度 q存储编号
deque<int> q;
for (int i = 1;i <= n;i++)
{
    while(!q.empty()&&i - q.front() >= m)
        q.pop_fornt();
    while(!q.empty()&&arr[q.back()] < arr[i]) //找最小值改成>
        q.pop_back();
    q.push_back(i);
    // if(i >= m)
    //     cout << arr[q.front()];
}