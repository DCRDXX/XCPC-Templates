形如这样： (a*n+b)*ksm(q,n-1); q != 0 && q != 1
s = (An + B)*ksm(q,n) - B;
A = a * inv(q-1);
B = (b - A) * inv(q-1);