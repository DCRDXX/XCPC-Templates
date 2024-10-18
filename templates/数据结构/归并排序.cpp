int arr[n];
int brr[n];
void msort (int l,int r)
{
    int mid = (l + r) >> 1;
    if(l == r)
        return;
    else
    {
        msort(l,mid);
        msort(mid+1,r);
    }
    int i = l;
    int j = mid+1;
    int t = l;

    while(i <= mid && j <= r)
    {
        if(arr[i] > arr[j])
        {
            ans += mid - i + 1;
            brr[t++] = arr[j++];
        }
        else
        {
            brr[t++] = arr[i++];
        }
    }

    while(i <= mid)
    {
            brr[t++] = arr[i++];
    }

    while(j <= r)
    {
            brr[t++] = arr[j++];
    }

    for (int i = l;i < t;i++)
        arr[i] = brr[i];
    return;
}