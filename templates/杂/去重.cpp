//去重后的范围 1 到 n
// 数组
sort(a+1,a+1+n);
int n = unique(a+1,a+1+n) - a;
n--;
// vector
sort(v.begin(),v.end());
int n = unique(v.begin(),v.end()) - v.begin();
n--;