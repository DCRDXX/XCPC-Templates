ll l = 0,r = 1e18;
while (l < r)
{
    ll lmid = l + (r-l)/3,rmid = r-(r-l)/3;
    if(f(rmid) < f(lmid))
        l = lmid + 1;
    else
        r = rmid - 1;
}
printf("%.10lf",f(l));