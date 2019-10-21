#include<bits/stdc++.h>
using namespace std;

long long bigMod(int a,int b,int M)
{
    if(b == 0) return 1 % M;
     long long x = bigMod(a,b/2,M);
    x = (x * x) % M;
    if(b % 2 == 1) x = (x * a) % M;
    return x;
}
int main()
{
    long double N;
    int n,k,testCases;
    long long second;
    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        scanf("%d %d",&n,&k);
        N = log10(n * 1.0) * k;
        N -= floor(N);
        N = pow(10,N);
        N = N * 100;
        second = bigMod(n % 1000,k,1000);
        printf("Case %d: %03d %03d\n",test,(int)N,second);
    }

    return 0;
}
